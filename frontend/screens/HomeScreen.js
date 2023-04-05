import {
  ScrollView,
  StyleSheet,
  Text,
  TouchableOpacity,
  View,
} from "react-native";
import React, { useState, useEffect } from "react";
import { Image, Switch } from "react-native";
import { auth } from "../firebase";
import { useNavigation } from "@react-navigation/native";
import { REACT_APP_API_URL } from "@env";
import { useFonts } from "expo-font";
import { WS } from "../utils/socket";
import { useDispatch, useSelector } from 'react-redux';
import { setOrder } from "../slices/orders";

export default function HomeScreen() {
  const navigation = useNavigation();

  const dispatch = useDispatch();
  const [isEnabled, setIsEnabled] = useState(false);

  useEffect(() => {
    WS.sendMessage(
      JSON.stringify({
        id: auth.currentUser.uid,
        online: isEnabled,
        type: "updateState",
      })
    );
  }, [isEnabled]);

  WS.onMessage((data) => {
    const msg = JSON.parse(JSON.parse(data.data))

    switch (msg.type) {
      case "user_recived_order":
        dispatch(setOrder({
          id: msg.order.id,
          pickUp: msg.order.pickUp,
          deliveryPoint: msg.order.deliveryPoint,
          expectedDeliveryTime: msg.order.expectedDeliveryTime,
          distance: msg.order.distance,
        }))
        navigation.replace("Order")
        break;
      default:
        alert("Recieved unkown message with type: " + msg.type)
        break;
    }
  })



  const toggleSwitch = () => {
    setIsEnabled(!isEnabled);
  };

  const homeIconPath = require("../assets/home.png");
  const ordersIconPath = require("../assets/orders.png");
  const profileIconPath = require("../assets/profile.png");
  const checklistPath = require("../assets/checklist.png");
  const [loaded] = useFonts({
    "anti-bold": require("../assets/fonts/AntipastoPro-ExtraBold_trial.ttf"),
    anti: require("../assets/fonts/AntipastoPro-DemiBold_trial.ttf"),
  });

  return (
    <View style={styles.container}>
      <ScrollView>
        <View style={styles.base}>
          <Image style={styles.bigImage} source={checklistPath} />
          <Text style={styles.header}>You have no current order</Text>
          <Text style={styles.text}>
            In order to recieve orders, make sure to switch on your
            availability.
          </Text>
          <View style={styles.divider} />
          <Switch
            trackColor={{ false: "#767577", true: "#81b0ff" }}
            thumbColor={isEnabled ? "lightgreen" : "red"}
            ios_backgroundColor="#3e3e3e"
            onValueChange={toggleSwitch}
            value={isEnabled}
            style={styles.switch}
          ></Switch>
          {isEnabled ? (
            <Text style={styles.text}>
              We will let you know when we have an order for you
            </Text>
          ) : (
            <Text style={styles.text}>
              You will not recieve any orders when you are offline
            </Text>
          )}
        </View>
      </ScrollView>

      <View style={styles.footer}>
        <TouchableOpacity style={styles.footerItem}>
          <Image style={styles.footerImage} source={homeIconPath} />
          <Text style={styles.footerText}>Home</Text>
        </TouchableOpacity>
        <TouchableOpacity style={styles.footerItem}>
          <Image style={styles.footerImage} source={ordersIconPath} />
          <Text style={styles.footerText}>Orders</Text>
        </TouchableOpacity>
        <TouchableOpacity style={styles.footerItem}>
          <Image style={styles.footerImage} source={profileIconPath} />
          <Text style={styles.footerText}>Profile</Text>
        </TouchableOpacity>
      </View>
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: "#FFB6B9",
    justifyContent: "center",
    display: "flex",
    paddingTop: "20%",
  },
  base: {
    alignItems: "center",
    justifyContent: "center",
    display: "flex",
  },
  header: {
    fontFamily: "anti-bold",
    fontWeight: "bold",
    fontSize: 26,
    color: "white",
  },
  divider: {
    marginBottom: 40,
  },
  footer: {
    display: "flex",
    alignItems: "center",
    justifyContent: "center",
    flexDirection: "row",
    gap: 80,
    padding: 8,
    backgroundColor: "#FAE3D9",
  },
  footerItem: {
    display: "flex",
    justifyContent: "center",
    alignItems: "center",
    gap: 4,
  },
  footerImage: {
    width: 32,
    height: 32,
  },
  footerText: {
    color: "grey",
    fontSize: 12,
    fontFamily: "anti",
    fontWeight: "bold",
  },
  bigImage: {
    width: 120,
    height: 120,
    marginBottom: 20,
  },
  switch: {
    transform: [{ scaleX: 2 }, { scaleY: 2 }],
  },
  text: {
    fontFamily: "anti",
    color: "white",
    fontSize: 20,
    fontWeight: 500,
    textAlign: "center",
  },
});
