import { ScrollView, StyleSheet, Text, TouchableOpacity, View } from 'react-native'
import React from 'react'
import { Image } from 'react-native'
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
                <Text>Welcome {auth.currentUser.id}</Text>
                <TouchableOpacity onPress={sendRequest}>
                    <Text>Send Request</Text>
                </TouchableOpacity>
                <TouchableOpacity onPress={handleSignOut}>
                    <Text>Sign out</Text>
                </TouchableOpacity>
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
    }
})