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

export default function HomeScreen() {
    const navigation = useNavigation();


    const homeIconPath = require("../assets/home.png");
    const ordersIconPath = require("../assets/orders.png");
    const profileIconPath = require("../assets/profile.png");
    const checklistPath = require("../assets/checklist.png");
    const mapPath = require("../assets/map.png");
    const dollarPath = require("../assets/dollar.png");
    const distancePath = require("../assets/distance.png");
    const deadlinePath = require("../assets/deadline.png");
    const restaurantPath = require("../assets/restaurant.png");
    const [loaded] = useFonts({
        "anti-bold": require("../assets/fonts/AntipastoPro-ExtraBold_trial.ttf"),
        anti: require("../assets/fonts/AntipastoPro-DemiBold_trial.ttf"),
    });

    return (
        <View style={styles.container}>
            <ScrollView>
                <View style={styles.base}>
                    <Image style={styles.bigImage} source={checklistPath} />
                    <Text style={styles.header}>You recieved an order!</Text>
                    <View style={styles.divider} />
                    <View style={styles.table}>


                        <View style={styles.flexRow}>
                            <Image style={styles.footerImage} source={restaurantPath} />
                            <View style={styles.dataContainer}>
                                <Text style={styles.textNoFont}>
                                    Mcdonalds,  Østerågade 17
                                </Text>
                            </View>
                        </View>

                        <View style={styles.flexRow}>
                            <Image style={styles.footerImage} source={mapPath} />
                            <View style={styles.dataContainer}>
                                <Text style={styles.textNoFont}>
                                    Danmarksgade 19, 9000 Aalborg
                                </Text>
                            </View>
                        </View>

                        <View style={styles.flexRow}>
                            <Image style={styles.footerImage} source={dollarPath} />
                            <View style={styles.dataContainer}>
                                <Text style={styles.textNoFont}>
                                    100,-
                                </Text>
                            </View>
                        </View>

                        <View style={styles.flexRow}>
                            <Image style={styles.footerImage} source={distancePath} />
                            <View style={styles.dataContainer}>
                                <Text style={styles.textNoFont}>
                                    4322 Meters
                                </Text>
                            </View>
                        </View>

                        <View style={styles.flexRow}>
                            <Image style={styles.footerImage} source={deadlinePath} />
                            <View style={styles.dataContainer}>
                                <Text style={styles.textNoFont}>
                                    16:30
                                </Text>
                            </View>
                        </View>
                    </View>


                </View>
            </ScrollView>
            <View style={styles.footer}>

                <TouchableOpacity onPress={() => console.log("lol")} style={styles.button}>
                    <Text style={styles.text}>Accept</Text>
                </TouchableOpacity>
                <TouchableOpacity onPress={() => console.log("lol")} style={styles.buttonDecline}>
                    <Text style={styles.text}>Decline</Text>
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

    table: {
        display: "flex",
        flexDirection: "column",
        alignItems: "center",
        justifyContent: "center",
        gap: 15,
    },

    flexRow: {
        display: "flex",
        flexDirection: "row",
        alignItems: "center",
        paddingLeft: 15,
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
        gap: 10,
        padding: 8,
        paddingVertical: 32,
    },
    footerItem: {
        display: "flex",
        justifyContent: "center",
        alignItems: "center",
        gap: 4,
    },
    dataContainer: {
        flex: 1,
        marginHorizontal: 20,
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
    textNoFont: {
        color: "white",
        fontSize: 20,
        fontWeight: 500,
    },
    text: {
        fontFamily: "anti",
        color: "white",
        fontSize: 20,
        fontWeight: 500,
        textAlign: "center",
    },
    button: {
        backgroundColor: "#1F7696",
        textAlign: "center",
        alignItems: "center",
        display: "flex",
        justifyContent: "center",
        height: 50,
        paddingHorizontal: 64,
        borderRadius: 18,
        fontWeight: 800,
    },
    buttonDecline: {
        backgroundColor: "#F36a71",
        textAlign: "center",
        alignItems: "center",
        display: "flex",
        justifyContent: "center",
        height: 50,
        paddingHorizontal: 64,
        borderRadius: 18,
        fontWeight: 800,
    }
});
