import { KeyboardAvoidingView, StyleSheet, Text, TextInput, TouchableOpacity, View } from 'react-native'
import React, { useState, useEffect } from 'react'
import { auth } from '../firebase';
import { useNavigation } from '@react-navigation/native';
import { Image } from 'react-native';
import { useFonts } from 'expo-font';

export default function LandingScreen() {

    let imagePath = require("../assets/courier.jpg");
    const [loaded] = useFonts({
        'anti-bold': require('../assets/fonts/AntipastoPro-ExtraBold_trial.ttf'),
        'anti': require('../assets/fonts/AntipastoPro-DemiBold_trial.ttf')
    });

    if (!loaded) return null;
    return (
        <View style={styles.container}>
            <View style={styles.imageContainer}>
                <Image style={styles.imageBanner} source={imagePath}>

                </Image>
            </View>

            <View style={styles.textContainer}>
                <Text style={styles.header}>Become a Food Courier today</Text>
                <Text style={styles.text}>We assign orders to you in a way that is fair for everyone</Text>
            </View>

            <View style={styles.buttonContainer}>
                <TouchableOpacity style={styles.registerButton}>
                    <Text style={styles.text}>Register</Text>
                </TouchableOpacity>
                <TouchableOpacity style={styles.loginButton}>
                    <Text style={styles.text}>Sign In</Text>
                </TouchableOpacity>
            </View>
        </View >
    )
}

const styles = StyleSheet.create({
    container: {
        flex: 1,
        justifyContent: 'center',
        alignItems: 'center',
        backgroundColor: "#FFB6B9",
        padding: 16,

    },
    textContainer: {
        padding: 48,
    },

    header: {
        fontSize: 38,
        fontWeight: 600,
        textAlign: "center",
        marginBottom: 16,
        color: "white",
        fontFamily: 'anti-bold',
    },
    text: {
        textAlign: "center",
        fontSize: 24,
        fontWeight: 500,
        color: "white",
        fontFamily: 'anti',

    },
    buttonContainer: {
        display: "flex",
        flexDirection: "row",
    },
    registerButton: {
        backgroundColor: "#61C0BF",
        textAlign: "center",
        alignItems: "center",
        display: "flex",
        justifyContent: "center",
        height: 50,
        paddingHorizontal: 32,
        borderTopLeftRadius: 18,
        borderBottomLeftRadius: 18,
        fontWeight: 800,
    },
    loginButton: {
        textAlign: "center",
        alignItems: "center",
        display: "flex",
        justifyContent: "center",
        height: 50,
        paddingHorizontal: 32,
        borderColor: "#61C0BF",
        borderWidth: 3,
        borderTopRightRadius: 18,
        borderBottomRightRadius: 18,

    },
    imageContainer: {
        maxWidth: 200,
        display: "flex",
        justifyContent: "center",
        alignItems: "center",
    },
    imageBanner: {
        borderRadius: 32,
        maxWidth: 350,
        maxHeight: 350,
    }
})