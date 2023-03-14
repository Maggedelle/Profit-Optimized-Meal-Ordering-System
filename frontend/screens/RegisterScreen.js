import { KeyboardAvoidingView, StyleSheet, Text, TextInput, TouchableOpacity, View } from 'react-native'
import React, { useState, useEffect } from 'react'
import { auth, db } from '../firebase';
import { useNavigation } from '@react-navigation/native';
import { useFonts } from 'expo-font';
import { Image } from 'react-native';
import { ref, set } from "firebase/database";

export default function RegisterScreen() {


    const [name, setName] = useState('');
    const [email, setEmail] = useState('');
    const [password, setPassword] = useState('');
    const [vehicle, setVehicle] = useState('');

    let car = require("../assets/car.png");
    let cycle = require("../assets/cycle.png");
    let motorCycle = require("../assets/motor-cycle.png");


    const [nameDone, setNameDone] = useState(false);
    const [vehicleDone, setVehicleDone] = useState(false);


    const [loaded] = useFonts({
        'anti-bold': require('../assets/fonts/AntipastoPro-ExtraBold_trial.ttf'),
        'anti': require('../assets/fonts/AntipastoPro-DemiBold_trial.ttf')
    });
    const navigation = useNavigation();
    useEffect(() => {
        const unsubscribe = auth.onAuthStateChanged(user => {
            if (user) {
                navigation.replace("Home");
            }
        })

        return unsubscribe;
    }, [])

    const handleVehicleClick = (vehicle) => {
        setVehicle(vehicle);
        setVehicleDone(true);
    }


    const handleSignUp = () => {
        auth.createUserWithEmailAndPassword(email, password)
            .then(userCredentials => {
                const user = userCredentials.user;
                set(ref(db, 'users/' + user.uid), {
                    email: user.email,
                    name: name,
                    vehicle: vehicle,
                }).then(result => {
                    console.log(result)
                }).catch(error => alert(error.message))
            }).catch(error => alert(error.message))
    }





    if (!loaded) return null;

    if (!nameDone) {
        return (
            <KeyboardAvoidingView style={styles.container} behavior="height">

                <Text style={styles.header}>Let's get you setted up!</Text>
                <Text style={styles.text}>What can we call you?</Text>
                <View style={styles.inputContainer}>
                    <TextInput placeholder='Full Name' style={styles.input} value={name} onChangeText={text => setName(text)} />
                </View>
                <View style={styles.buttonContainer}>
                    <TouchableOpacity onPress={() => setNameDone(true)} style={styles.button}>
                        <Text style={styles.text}>Continue</Text>
                    </TouchableOpacity>
                </View>
            </KeyboardAvoidingView>
        )
    } else if (!vehicleDone) {
        return (

            <KeyboardAvoidingView style={styles.container} behavior="height">

                <Text style={styles.header}>Nice to meet you {name}!</Text>
                <Text style={styles.text}>Which vehicle do you plan on using?</Text>
                <View style={styles.icons}>


                    <TouchableOpacity style={styles.iconContainer} onPress={() => handleVehicleClick("car")}>
                        <Image style={styles.icon} source={car} />
                    </TouchableOpacity>
                    <TouchableOpacity style={styles.iconContainer} onPress={() => handleVehicleClick("motorCycle")}>
                        <Image style={styles.icon} source={motorCycle} />
                    </TouchableOpacity>
                    <TouchableOpacity style={styles.iconContainer} onPress={() => handleVehicleClick("cycle")}>
                        <Image style={styles.icon} source={cycle} />
                    </TouchableOpacity>
                </View>


            </KeyboardAvoidingView>
        )
    } else {
        return (
            <KeyboardAvoidingView style={styles.container} behavior="height">
                <Text style={styles.header}>Almost there...</Text>
                <Text style={styles.text}>Please create a login</Text>
                <View style={styles.inputContainer}>
                    <TextInput placeholder='Email' style={styles.input} value={email} onChangeText={text => setEmail(text)} />
                    <TextInput placeholder='Password' value={password} onChangeText={text => setPassword(text)} style={styles.input} secureTextEntry />
                </View>

                <View style={styles.buttonContainer}>
                    <TouchableOpacity onPress={() => handleSignUp()} style={styles.button}>
                        <Text style={styles.text}>Create Account</Text>
                    </TouchableOpacity>
                </View>
            </KeyboardAvoidingView>
        )
    }

}

const styles = StyleSheet.create({
    container: {
        flex: 1,
        justifyContent: 'center',
        alignItems: 'center',
        backgroundColor: "#FFB6B9",
        padding: 8

    },
    inputContainer: {
        width: '80%'
    },
    input: {
        paddingHorizontal: 15,
        paddingVertical: 10,
        borderRadius: 10,
        marginTop: 5,
        backgroundColor: "white",
    },
    buttonContainer: {
        width: '60%',
        justifyContent: 'center',
        alignItems: 'center',
        marginTop: 40,
    },

    button: {
        backgroundColor: "#61C0BF",
        textAlign: "center",
        alignItems: "center",
        display: "flex",
        justifyContent: "center",
        height: 50,
        paddingHorizontal: 64,
        borderRadius: 18,
        fontWeight: 800,
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

    icons: {
        display: "flex",
        flexDirection: "row",
    },

    iconContainer: {
        width: 100,
        height: 140,
        alignItems: "center",
        justifyContent: "center",
        margin: 20,
        borderWidth: 3,
        overflow: "hidden",
        borderColor: "#61C0BF",
        borderRadius: 20
    },

    icon: {
        width: '100%',
        height: undefined,
        alignSelf: 'stretch',
        resizeMode: 'contain',
        aspectRatio: 1,
    }
})