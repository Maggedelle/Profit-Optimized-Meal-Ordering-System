import { KeyboardAvoidingView, StyleSheet, Text, TextInput, TouchableOpacity, View } from 'react-native'
import React, { useState, useEffect } from 'react'
import { auth, db } from '../firebase';
import { useNavigation } from '@react-navigation/native';
import { useFonts } from 'expo-font';
import { Image } from 'react-native';
import { ref, set } from "firebase/database";
import MapView, { Marker, Circle } from 'react-native-maps';
import { Slider } from '@miblanchard/react-native-slider';

export default function RegisterScreen() {


    const [name, setName] = useState('');
    const [email, setEmail] = useState('');
    const [password, setPassword] = useState('');
    const [vehicle, setVehicle] = useState('');
    const [coordinates, setCoordinates] = useState({
        latitude: 57.0488,
        longitude: 9.9217
    });
    let car = require("../assets/car.png");
    let cycle = require("../assets/cycle.png");
    let motorCycle = require("../assets/motor-cycle.png");


    const [nameDone, setNameDone] = useState(false);
    const [vehicleDone, setVehicleDone] = useState(false);
    const [mapLocationDone, setMapLocationDone] = useState(false);
    const [mapDone, setMapDone] = useState(false);

    const [circleRadius, setCircleRadius] = useState(1000);

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
                    location: {
                        longitude: coordinates.longitude,
                        latitude: coordinates.latitude
                    }
                }).then(result => {

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


                    <TouchableOpacity style={styles.wrapperCar} onPress={() => handleVehicleClick("car")}>
                        <View style={styles.wrapperIcon}>
                            <Image style={styles.icon} source={car} />
                        </View>
                        <View style={styles.wrapperText}>
                            <Text style={styles.boldBlackText}>Car</Text>
                            <Text>50-80 km/h</Text>
                        </View>
                    </TouchableOpacity>
                    <TouchableOpacity style={styles.wrapperMotorCycle} onPress={() => handleVehicleClick("motorCycle")}>

                        <View style={styles.wrapperIcon}>

                            <Image style={styles.icon} source={motorCycle} />
                        </View>
                        <View style={styles.wrapperText}>
                            <Text style={styles.boldBlackText}>Scooter</Text>
                            <Text>30-45 km/h</Text>
                        </View>
                    </TouchableOpacity>
                    <TouchableOpacity style={styles.wrapperCycle} onPress={() => handleVehicleClick("cycle")}>
                        <View style={styles.wrapperIcon}>

                            <Image style={styles.icon} source={cycle} />
                        </View>
                        <View style={styles.wrapperText}>
                            <Text style={styles.boldWhiteText}>Bike</Text>
                            <Text style={styles.whiteTextNoFont}>15-25 km/h</Text>
                        </View>
                    </TouchableOpacity>
                </View>


            </KeyboardAvoidingView>
        )
    } else if (!mapDone) {
        return (
            <View>
                <View style={styles.absoluteContainer}>
                    <Text style={styles.mapText} >
                        {!mapLocationDone ? "Please drag the marker to your location, so that we can assign you relevant orders"
                            : "Great, now pick the radius in which you are willing to pick up orders"}
                    </Text>
                    {mapLocationDone && <Slider
                        value={circleRadius}
                        onValueChange={value => setCircleRadius(value[0])}
                        minimumValue={500}
                        maximumValue={10000}
                    />}
                    <TouchableOpacity onPress={() => mapLocationDone ? setMapDone(true) : setMapLocationDone(true)} style={styles.mapButton}>
                        <Text style={styles.text}>Continue</Text>
                    </TouchableOpacity>
                </View>
                <MapView style={styles.map}

                    initialRegion={{
                        latitude: 57.0488,
                        longitude: 9.9217,
                        latitudeDelta: 0.0922,
                        longitudeDelta: 0.0421,
                    }}
                >
                    <Marker draggable
                        coordinate={{
                            latitude: 57.0488,
                            longitude: 9.9217,
                        }}
                        onDragEnd={(e) => setCoordinates(e.nativeEvent.coordinate)}
                    />
                    {mapLocationDone &&
                        <Circle
                            center={coordinates}
                            radius={circleRadius}
                            strokeWidth={1}
                            strokeColor={'#1a66ff'}
                            fillColor={'rgba(230,238,255,0.5)'}

                        />


                    }
                </MapView>
            </View>
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
        padding: 24

    },
    inputContainer: {
        width: '80%'
    },
    absoluteContainer: {
        position: "absolute",
        zIndex: 10,
        bottom: 0,
        backgroundColor: "#16C596",
        width: "100%",
        padding: 15,
    },
    mapText: {
        textAlign: "center",
        fontSize: 24,
        fontWeight: 500,
        fontFamily: 'anti',
        color: "white",
    },
    mapButton: {
        backgroundColor: "#F36a71",
        textAlign: "center",
        alignItems: "center",
        display: "flex",
        justifyContent: "center",
        height: 50,
        paddingHorizontal: 64,
        borderRadius: 18,
        fontWeight: 800,
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

    map: {
        width: '100%',
        height: '100%',
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
    },

    wrapperCar: {
        width: "100%",
        height: 140,
        alignItems: "center",
        margin: 20,
        overflow: "hidden",
        backgroundColor: "#FDF4F5",
        padding: 16,
        display: "flex",
        flexDirection: "row",
        gap: 20,
        borderRadius: 20,
    },

    wrapperMotorCycle: {
        width: "100%",
        height: 140,
        alignItems: "center",
        margin: 20,
        overflow: "hidden",
        backgroundColor: "#FFF8EF",
        padding: 16,
        display: "flex",
        flexDirection: "row",
        gap: 20,
        borderRadius: 20,
    },

    wrapperCycle: {
        width: "100%",
        height: 140,
        alignItems: "center",
        margin: 20,
        overflow: "hidden",
        backgroundColor: "#4FCAAE",
        padding: 16,
        display: "flex",
        flexDirection: "row",
        gap: 20,
        borderRadius: 20,
    },

    wrapperIcon: {
        width: "45%",
    },

    wrapperText: {
        flex: 1,
    },

    boldBlackText: {
        fontWeight: 600,
        fontFamily: 'anti-bold',
        fontSize: 20,
    },
    boldWhiteText: {
        fontWeight: 600,
        fontFamily: 'anti-bold',
        fontSize: 20,
        color: "white",
    },


    whiteTextNoFont: {
        color: "white",
    },


    icon: {
        width: '100%',
        height: undefined,
        alignSelf: 'stretch',
        resizeMode: 'contain',
        aspectRatio: 1,
    }
})