import { ScrollView, StyleSheet, Text, TouchableOpacity, View } from 'react-native'
import React, { useState } from 'react'
import { Image, Switch } from 'react-native'
import { auth } from '../firebase'
import { useNavigation } from '@react-navigation/native'
import { REACT_APP_API_URL } from "@env";
import { useFonts } from 'expo-font';

export default function HomeScreen() {

    const navigation = useNavigation();
    const handleSignOut = () => {
        auth.signOut()
            .then(() => {
                navigation.replace("Landing");
            })
            .catch(error => alert(error.message))
    }

    const sendRequest = () => {
        fetch(REACT_APP_API_URL + '/worker/state', {
            method: 'POST',
            headers: {
                Acccept: 'application/json',
                'Content-Type': 'application/json',
            },
            body: JSON.stringify({
                someParam: "Test"
            })
        }).then(json => {
            console.log(json)
        }).catch(error => {
            alert(error);
        })
    }

    const [isEnabled, setIsEnabled] = useState(false);
    const toggleSwitch = () => setIsEnabled(previousState => !previousState);

    const homeIconPath = require("../assets/home.png");
    const ordersIconPath = require("../assets/orders.png");
    const profileIconPath = require("../assets/profile.png")

    const [loaded] = useFonts({
        'anti-bold': require('../assets/fonts/AntipastoPro-ExtraBold_trial.ttf'),
        'anti': require('../assets/fonts/AntipastoPro-DemiBold_trial.ttf')
    });


    return (
        <View style={styles.container}>
            <ScrollView>
                <View style={styles.base}>
                    <Text style={styles.header}>
                        Ready to recieve orders?
                    </Text>
                    <Text style={styles.text}>
                        Click the switch to change your online status!
                    </Text>
                    <Switch
                        trackColor={{ false: '#767577', true: '#81b0ff' }}
                        thumbColor={isEnabled ? 'lightgreen' : 'red'}
                        ios_backgroundColor="#3e3e3e"
                        onValueChange={toggleSwitch}
                        value={isEnabled}
                        style={styles.switch}
                    >

                    </Switch>
                    {isEnabled ? (<Text style={styles.text}>We will let you know when we have an order for you</Text>
                    ) : (<Text style={styles.text}>You will not recieve any orders when you are offline</Text>)}
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
    )
}

const styles = StyleSheet.create({
    container: {
        flex: 1,
        backgroundColor: "#FFB6B9",
        paddingTop: 40,
    },
    base: {
        alignItems: "center",
        justifyContent: "center",
        display: "flex"
    },
    header: {
        fontFamily: "anti-bold",
        fontWeight: 'bold',
        fontSize: 32,
        color: "white"
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
        fontFamily: 'anti',
        fontWeight: "bold"
    },
    switch: {
        transform: [{ scaleX: 2 }, { scaleY: 2 }]
    },
    text: {
        fontFamily: "anti",
        color: "white",
        fontSize: 20,
        fontWeight: 500,
        textAlign: "center",
    }
})