import 'dart:ffi';
import 'dart:ui';

import 'package:firebase_database/firebase_database.dart';
import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'package:eindwerk_app/homepage.dart';
import 'package:responsive_framework/responsive_framework.dart';

class MymobileWeekplanning extends StatefulWidget {
  @override
  _MymobileWeekplanningState createState() => _MymobileWeekplanningState();
}

class _MymobileWeekplanningState extends State<MymobileWeekplanning> {
  final database = FirebaseDatabase.instance.ref();

  bool maandag_Boiler = true;
  bool maandag_Fornuis = true;
  bool maandag_Lichten = true;
  bool maandag_Vaatwas = true;

  bool dinsdag_Boiler = true;
  bool dinsdag_Fornuis = true;
  bool dinsdag_Lichten = true;
  bool dinsdag_Vaatwas = true;

  bool woensdag_Boiler = true;
  bool woensdag_Fornuis = true;
  bool woensdag_Lichten = true;
  bool woensdag_Vaatwas = true;

  bool donderdag_Boiler = true;
  bool donderdag_Fornuis = true;
  bool donderdag_Lichten = true;
  bool donderdag_Vaatwas = true;

  bool vrijdag_Boiler = true;
  bool vrijdag_Fornuis = true;
  bool vrijdag_Lichten = true;
  bool vrijdag_Vaatwas = true;

  bool zaterdag_Boiler = true;
  bool zaterdag_Fornuis = true;
  bool zaterdag_Lichten = true;
  bool zaterdag_Vaatwas = true;

  bool zondag_Boiler = true;
  bool zondag_Fornuis = true;
  bool zondag_Lichten = true;
  bool zondag_Vaatwas = true;

  bool Reset = false;

  void initState() {
    super.initState();
    WidgetsBinding.instance.addPostFrameCallback((_) => setState(() {
          final root = database.child('Dagen/');
          final resetDatabase = database.child('/');

          root.child('Maandag/Boiler/').get().then((DataSnapshot snapshot) {
            setState(() {
              maandag_Boiler = snapshot.value;
            });
          });
          root.child('Maandag/Fornuis/').get().then((DataSnapshot snapshot) {
            setState(() {
              maandag_Fornuis = snapshot.value;
            });
          });
          root.child('Maandag/Lichten/').get().then((DataSnapshot snapshot) {
            setState(() {
              maandag_Lichten = snapshot.value;
            });
          });
          root.child('Maandag/Vaatwas/').get().then((DataSnapshot snapshot) {
            setState(() {
              maandag_Vaatwas = snapshot.value;
            });
          });

          root.child('Dinsdag/Boiler/').get().then((DataSnapshot snapshot) {
            setState(() {
              dinsdag_Boiler = snapshot.value;
            });
          });
          root.child('Dinsdag/Fornuis/').get().then((DataSnapshot snapshot) {
            setState(() {
              dinsdag_Fornuis = snapshot.value;
            });
          });
          root.child('Dinsdag/Lichten/').get().then((DataSnapshot snapshot) {
            setState(() {
              dinsdag_Lichten = snapshot.value;
            });
          });
          root.child('Dinsdag/Vaatwas/').get().then((DataSnapshot snapshot) {
            setState(() {
              dinsdag_Vaatwas = snapshot.value;
            });
          });

          root.child('Woensdag/Boiler/').get().then((DataSnapshot snapshot) {
            setState(() {
              woensdag_Boiler = snapshot.value;
            });
          });
          root.child('Woensdag/Fornuis/').get().then((DataSnapshot snapshot) {
            setState(() {
              woensdag_Fornuis = snapshot.value;
            });
          });
          root.child('Woensdag/Lichten/').get().then((DataSnapshot snapshot) {
            setState(() {
              woensdag_Lichten = snapshot.value;
            });
          });
          root.child('Woensdag/Vaatwas/').get().then((DataSnapshot snapshot) {
            setState(() {
              woensdag_Vaatwas = snapshot.value;
            });
          });

          root.child('Donderdag/Boiler/').get().then((DataSnapshot snapshot) {
            setState(() {
              donderdag_Boiler = snapshot.value;
            });
          });
          root.child('Donderdag/Fornuis/').get().then((DataSnapshot snapshot) {
            setState(() {
              donderdag_Fornuis = snapshot.value;
            });
          });
          root.child('Donderdag/Lichten/').get().then((DataSnapshot snapshot) {
            setState(() {
              donderdag_Lichten = snapshot.value;
            });
          });
          root.child('Donderdag/Vaatwas/').get().then((DataSnapshot snapshot) {
            setState(() {
              donderdag_Vaatwas = snapshot.value;
            });
          });

          root.child('Vrijdag/Boiler/').get().then((DataSnapshot snapshot) {
            setState(() {
              vrijdag_Boiler = snapshot.value;
            });
          });
          root.child('Vrijdag/Fornuis/').get().then((DataSnapshot snapshot) {
            setState(() {
              vrijdag_Fornuis = snapshot.value;
            });
          });
          root.child('Vrijdag/Lichten/').get().then((DataSnapshot snapshot) {
            setState(() {
              vrijdag_Lichten = snapshot.value;
            });
          });
          root.child('Vrijdag/Vaatwas/').get().then((DataSnapshot snapshot) {
            setState(() {
              vrijdag_Vaatwas = snapshot.value;
            });
          });

          root.child('Zaterdag/Boiler/').get().then((DataSnapshot snapshot) {
            setState(() {
              zaterdag_Boiler = snapshot.value;
            });
          });
          root.child('Zaterdag/Fornuis/').get().then((DataSnapshot snapshot) {
            setState(() {
              zaterdag_Fornuis = snapshot.value;
            });
          });
          root.child('Zaterdag/Lichten/').get().then((DataSnapshot snapshot) {
            setState(() {
              zaterdag_Lichten = snapshot.value;
            });
          });
          root.child('Zaterdag/Vaatwas').get().then((DataSnapshot snapshot) {
            setState(() {
              zaterdag_Vaatwas = snapshot.value;
            });
          });

          root.child('Zondag/Boiler/').get().then((DataSnapshot snapshot) {
            setState(() {
              zondag_Boiler = snapshot.value;
            });
          });
          root.child('Zondag/Fornuis/').get().then((DataSnapshot snapshot) {
            setState(() {
              zondag_Fornuis = snapshot.value;
            });
          });
          root.child('Zondag/Lichten/').get().then((DataSnapshot snapshot) {
            setState(() {
              zondag_Lichten = snapshot.value;
            });
          });
          root.child('Zondag/Vaatwas/').get().then((DataSnapshot snapshot) {
            setState(() {
              zondag_Vaatwas = snapshot.value;
            });
          });

          resetDatabase.child('reset/').get().then((DataSnapshot snapshot) {
            setState(() {
              Reset = snapshot.value;
            });
          });
        }));
  }

  @override
  Widget build(BuildContext context) {
    final dagen = database.child('Dagen/');
    final root = database.child('/');

    void einde() {
      dagen.child('Maandag/').update({"Boiler": maandag_Boiler});
      dagen.child('Maandag/').update({"Fornuis": maandag_Fornuis});
      dagen.child('Maandag/').update({"Lichten": maandag_Lichten});
      dagen.child('Maandag/').update({"Vaatwas": maandag_Vaatwas});

      dagen.child('Dinsdag/').update({"Boiler": dinsdag_Boiler});
      dagen.child('Dinsdag/').update({"Fornuis": dinsdag_Fornuis});
      dagen.child('Dinsdag/').update({"Lichten": dinsdag_Lichten});
      dagen.child('Dinsdag/').update({"Vaatwas": dinsdag_Vaatwas});

      dagen.child('Woensdag/').update({"Boiler": woensdag_Boiler});
      dagen.child('Woensdag/').update({"Fornuis": woensdag_Fornuis});
      dagen.child('Woensdag/').update({"Lichten": woensdag_Lichten});
      dagen.child('Woensdag/').update({"Vaatwas": woensdag_Vaatwas});

      dagen.child('Donderdag/').update({"Boiler": donderdag_Boiler});
      dagen.child('Donderdag/').update({"Fornuis": donderdag_Fornuis});
      dagen.child('Donderdag/').update({"Lichten": donderdag_Lichten});
      dagen.child('Donderdag/').update({"Vaatwas": donderdag_Vaatwas});

      dagen.child('Vrijdag/').update({"Boiler": vrijdag_Boiler});
      dagen.child('Vrijdag/').update({"Fornuis": vrijdag_Fornuis});
      dagen.child('Vrijdag/').update({"Lichten": vrijdag_Lichten});
      dagen.child('Vrijdag/').update({"Vaatwas": vrijdag_Vaatwas});

      dagen.child('Zaterdag/').update({"Boiler": zaterdag_Boiler});
      dagen.child('Zaterdag/').update({"Fornuis": zaterdag_Fornuis});
      dagen.child('Zaterdag/').update({"Lichten": zaterdag_Lichten});
      dagen.child('Zaterdag/').update({"Vaatwas": zaterdag_Vaatwas});

      dagen.child('Zondag/').update({"Boiler": zondag_Boiler});
      dagen.child('Zondag/').update({"Fornuis": zondag_Fornuis});
      dagen.child('Zondag/').update({"Lichten": zondag_Lichten});
      dagen.child('Zondag/').update({"Vaatwas": zondag_Vaatwas});

      root.update({"reset": Reset});
    }

    return Scaffold(
      body: ListView(
        padding: EdgeInsets.only(left: 10),
        children: [
          Column(
            mainAxisAlignment: MainAxisAlignment.spaceEvenly,
            children: [
              SizedBox(
                height: 50,
              ),
              Container(
                height: 275,
                width: 275,
                alignment: Alignment.center,
                decoration: BoxDecoration(
                  boxShadow: [
                    BoxShadow(
                      color: Colors.grey.withOpacity(0.2),
                      spreadRadius: 5,
                      blurRadius: 7,
                      offset: Offset(0, 3), // changes position of shadow
                    ),
                  ],
                  borderRadius: BorderRadius.circular(20),
                  color: Color.fromRGBO(30, 30, 30, 1),
                ),
                child: Padding(
                  padding: const EdgeInsets.only(left: 70, top: 35),
                  child: Column(
                      crossAxisAlignment: CrossAxisAlignment.start,
                      mainAxisSize: MainAxisSize.max,
                      children: [
                        Row(children: [
                          Text(
                            "Maandag",
                            style: TextStyle(
                                color: Color.fromRGBO(92, 191, 204, 1),
                                fontSize: 30),
                          ),
                        ]),
                        Row(children: [
                          Text(
                            "Boiler",
                            style: TextStyle(
                                color: Color.fromRGBO(92, 191, 204, 1),
                                fontSize: 20),
                          ),
                          Switch(
                            value: maandag_Boiler,
                            onChanged: (bool newValue) {
                              setState(() {
                                maandag_Boiler = newValue;
                                einde();
                              });
                            },
                          )
                        ]),
                        Row(children: [
                          Text(
                            "Fornuis",
                            style: TextStyle(
                                color: Color.fromRGBO(92, 191, 204, 1),
                                fontSize: 20),
                          ),
                          Switch(
                            value: maandag_Fornuis,
                            onChanged: (bool newValue) {
                              setState(() {
                                maandag_Fornuis = newValue;
                                einde();
                              });
                            },
                          )
                        ]),
                        Row(children: [
                          Text(
                            "Lichten",
                            style: TextStyle(
                                color: Color.fromRGBO(92, 191, 204, 1),
                                fontSize: 20),
                          ),
                          Switch(
                            value: maandag_Lichten,
                            onChanged: (bool newValue) {
                              setState(() {
                                maandag_Lichten = newValue;
                                einde();
                              });
                            },
                          )
                        ]),
                        Row(children: [
                          Text(
                            "Vaatwas",
                            style: TextStyle(
                                color: Color.fromRGBO(92, 191, 204, 1),
                                fontSize: 20),
                          ),
                          Switch(
                            value: maandag_Vaatwas,
                            onChanged: (bool newValue) {
                              setState(() {
                                maandag_Vaatwas = newValue;
                                einde();
                              });
                            },
                          )
                        ]),
                      ]),
                ),
              ),
              SizedBox(
                height: 30,
              ),
              Container(
                height: 275,
                width: 275,
                alignment: Alignment.center,
                decoration: BoxDecoration(
                  boxShadow: [
                    BoxShadow(
                      color: Colors.grey.withOpacity(0.2),
                      spreadRadius: 5,
                      blurRadius: 7,
                      offset: Offset(0, 3), // changes position of shadow
                    ),
                  ],
                  borderRadius: BorderRadius.circular(20),
                  color: Color.fromRGBO(30, 30, 30, 1),
                ),
                child: Padding(
                  padding: const EdgeInsets.only(left: 70, top: 35),
                  child: Column(
                      crossAxisAlignment: CrossAxisAlignment.start,
                      mainAxisSize: MainAxisSize.max,
                      children: [
                        Row(children: [
                          Text(
                            "Dinsdag",
                            style: TextStyle(
                                color: Color.fromRGBO(92, 191, 204, 1),
                                fontSize: 30),
                          ),
                        ]),
                        Row(children: [
                          Text(
                            "Boiler",
                            style: TextStyle(
                                color: Color.fromRGBO(92, 191, 204, 1),
                                fontSize: 20),
                          ),
                          Switch(
                            value: dinsdag_Boiler,
                            onChanged: (bool newValue) {
                              setState(() {
                                dinsdag_Boiler = newValue;
                                einde();
                              });
                            },
                          )
                        ]),
                        Row(children: [
                          Text(
                            "Fornuis",
                            style: TextStyle(
                                color: Color.fromRGBO(92, 191, 204, 1),
                                fontSize: 20),
                          ),
                          Switch(
                            value: dinsdag_Fornuis,
                            onChanged: (bool newValue) {
                              setState(() {
                                dinsdag_Fornuis = newValue;
                                einde();
                              });
                            },
                          )
                        ]),
                        Row(children: [
                          Text(
                            "Lichten",
                            style: TextStyle(
                                color: Color.fromRGBO(92, 191, 204, 1),
                                fontSize: 20),
                          ),
                          Switch(
                            value: dinsdag_Lichten,
                            onChanged: (bool newValue) {
                              setState(() {
                                dinsdag_Lichten = newValue;
                                einde();
                              });
                            },
                          )
                        ]),
                        Row(children: [
                          Text(
                            "Vaatwas",
                            style: TextStyle(
                                color: Color.fromRGBO(92, 191, 204, 1),
                                fontSize: 20),
                          ),
                          Switch(
                            value: dinsdag_Vaatwas,
                            onChanged: (bool newValue) {
                              setState(() {
                                dinsdag_Vaatwas = newValue;
                                einde();
                              });
                            },
                          )
                        ]),
                      ]),
                ),
              ),
              SizedBox(
                height: 30,
              ),
              Container(
                height: 275,
                width: 275,
                alignment: Alignment.center,
                decoration: BoxDecoration(
                  boxShadow: [
                    BoxShadow(
                      color: Colors.grey.withOpacity(0.2),
                      spreadRadius: 5,
                      blurRadius: 7,
                      offset: Offset(0, 3), // changes position of shadow
                    ),
                  ],
                  borderRadius: BorderRadius.circular(20),
                  color: Color.fromRGBO(30, 30, 30, 1),
                ),
                child: Padding(
                  padding: const EdgeInsets.only(left: 70, top: 35),
                  child: Column(
                      crossAxisAlignment: CrossAxisAlignment.start,
                      mainAxisSize: MainAxisSize.max,
                      children: [
                        Row(children: [
                          Text(
                            "Woensdag",
                            style: TextStyle(
                                color: Color.fromRGBO(92, 191, 204, 1),
                                fontSize: 30),
                          ),
                        ]),
                        Row(children: [
                          Text(
                            "Boiler",
                            style: TextStyle(
                                color: Color.fromRGBO(92, 191, 204, 1),
                                fontSize: 20),
                          ),
                          Switch(
                            value: woensdag_Boiler,
                            onChanged: (bool newValue) {
                              setState(() {
                                woensdag_Boiler = newValue;
                                einde();
                              });
                            },
                          )
                        ]),
                        Row(children: [
                          Text(
                            "Fornuis",
                            style: TextStyle(
                                color: Color.fromRGBO(92, 191, 204, 1),
                                fontSize: 20),
                          ),
                          Switch(
                            value: woensdag_Fornuis,
                            onChanged: (bool newValue) {
                              setState(() {
                                woensdag_Fornuis = newValue;
                                einde();
                              });
                            },
                          )
                        ]),
                        Row(children: [
                          Text(
                            "Lichten",
                            style: TextStyle(
                                color: Color.fromRGBO(92, 191, 204, 1),
                                fontSize: 20),
                          ),
                          Switch(
                            value: woensdag_Lichten,
                            onChanged: (bool newValue) {
                              setState(() {
                                woensdag_Lichten = newValue;
                                einde();
                              });
                            },
                          )
                        ]),
                        Row(children: [
                          Text(
                            "Vaatwas",
                            style: TextStyle(
                                color: Color.fromRGBO(92, 191, 204, 1),
                                fontSize: 20),
                          ),
                          Switch(
                            value: woensdag_Vaatwas,
                            onChanged: (bool newValue) {
                              setState(() {
                                woensdag_Vaatwas = newValue;
                                einde();
                              });
                            },
                          )
                        ]),
                      ]),
                ),
              ),
              SizedBox(
                height: 30,
              ),
              Container(
                height: 275,
                width: 275,
                alignment: Alignment.center,
                decoration: BoxDecoration(
                  boxShadow: [
                    BoxShadow(
                      color: Colors.grey.withOpacity(0.2),
                      spreadRadius: 5,
                      blurRadius: 7,
                      offset: Offset(0, 3), // changes position of shadow
                    ),
                  ],
                  borderRadius: BorderRadius.circular(20),
                  color: Color.fromRGBO(30, 30, 30, 1),
                ),
                child: Padding(
                  padding: const EdgeInsets.only(left: 70, top: 35),
                  child: Column(
                      crossAxisAlignment: CrossAxisAlignment.start,
                      mainAxisSize: MainAxisSize.max,
                      children: [
                        Row(children: [
                          Text(
                            "Donderdag",
                            style: TextStyle(
                                color: Color.fromRGBO(92, 191, 204, 1),
                                fontSize: 30),
                          ),
                        ]),
                        Row(children: [
                          Text(
                            "Boiler",
                            style: TextStyle(
                                color: Color.fromRGBO(92, 191, 204, 1),
                                fontSize: 20),
                          ),
                          Switch(
                            value: donderdag_Boiler,
                            onChanged: (bool newValue) {
                              setState(() {
                                donderdag_Boiler = newValue;
                                einde();
                              });
                            },
                          )
                        ]),
                        Row(children: [
                          Text(
                            "Fornuis",
                            style: TextStyle(
                                color: Color.fromRGBO(92, 191, 204, 1),
                                fontSize: 20),
                          ),
                          Switch(
                            value: donderdag_Fornuis,
                            onChanged: (bool newValue) {
                              setState(() {
                                donderdag_Fornuis = newValue;
                                einde();
                              });
                            },
                          )
                        ]),
                        Row(children: [
                          Text(
                            "Lichten",
                            style: TextStyle(
                                color: Color.fromRGBO(92, 191, 204, 1),
                                fontSize: 20),
                          ),
                          Switch(
                            value: donderdag_Lichten,
                            onChanged: (bool newValue) {
                              setState(() {
                                donderdag_Lichten = newValue;
                                einde();
                              });
                            },
                          )
                        ]),
                        Row(children: [
                          Text(
                            "Vaatwas",
                            style: TextStyle(
                                color: Color.fromRGBO(92, 191, 204, 1),
                                fontSize: 20),
                          ),
                          Switch(
                            value: donderdag_Vaatwas,
                            onChanged: (bool newValue) {
                              setState(() {
                                donderdag_Vaatwas = newValue;
                                einde();
                              });
                            },
                          )
                        ]),
                      ]),
                ),
              ),
            ],
          ),
          Column(
            mainAxisAlignment: MainAxisAlignment.spaceEvenly,
            children: [
              SizedBox(
                height: 30,
              ),
              Container(
                height: 275,
                width: 275,
                alignment: Alignment.center,
                decoration: BoxDecoration(
                  boxShadow: [
                    BoxShadow(
                      color: Colors.grey.withOpacity(0.2),
                      spreadRadius: 5,
                      blurRadius: 7,
                      offset: Offset(0, 3), // changes position of shadow
                    ),
                  ],
                  borderRadius: BorderRadius.circular(20),
                  color: Color.fromRGBO(30, 30, 30, 1),
                ),
                child: Padding(
                  padding: const EdgeInsets.only(left: 70, top: 35),
                  child: Column(
                      crossAxisAlignment: CrossAxisAlignment.start,
                      mainAxisSize: MainAxisSize.max,
                      children: [
                        Row(children: [
                          Text(
                            "Vrijdag",
                            style: TextStyle(
                                color: Color.fromRGBO(92, 191, 204, 1),
                                fontSize: 30),
                          ),
                        ]),
                        Row(children: [
                          Text(
                            "Boiler",
                            style: TextStyle(
                                color: Color.fromRGBO(92, 191, 204, 1),
                                fontSize: 20),
                          ),
                          Switch(
                            value: vrijdag_Boiler,
                            onChanged: (bool newValue) {
                              setState(() {
                                vrijdag_Boiler = newValue;
                                einde();
                              });
                            },
                          )
                        ]),
                        Row(children: [
                          Text(
                            "Fornuis",
                            style: TextStyle(
                                color: Color.fromRGBO(92, 191, 204, 1),
                                fontSize: 20),
                          ),
                          Switch(
                            value: vrijdag_Fornuis,
                            onChanged: (bool newValue) {
                              setState(() {
                                vrijdag_Fornuis = newValue;
                                einde();
                              });
                            },
                          )
                        ]),
                        Row(children: [
                          Text(
                            "Lichten",
                            style: TextStyle(
                                color: Color.fromRGBO(92, 191, 204, 1),
                                fontSize: 20),
                          ),
                          Switch(
                            value: vrijdag_Lichten,
                            onChanged: (bool newValue) {
                              setState(() {
                                vrijdag_Lichten = newValue;
                                einde();
                              });
                            },
                          )
                        ]),
                        Row(children: [
                          Text(
                            "Vaatwas",
                            style: TextStyle(
                                color: Color.fromRGBO(92, 191, 204, 1),
                                fontSize: 20),
                          ),
                          Switch(
                            value: vrijdag_Vaatwas,
                            onChanged: (bool newValue) {
                              setState(() {
                                vrijdag_Vaatwas = newValue;
                                einde();
                              });
                            },
                          )
                        ]),
                      ]),
                ),
              ),
              SizedBox(
                height: 30,
              ),
              Container(
                height: 275,
                width: 275,
                alignment: Alignment.center,
                decoration: BoxDecoration(
                  boxShadow: [
                    BoxShadow(
                      color: Colors.grey.withOpacity(0.2),
                      spreadRadius: 5,
                      blurRadius: 7,
                      offset: Offset(0, 3), // changes position of shadow
                    ),
                  ],
                  borderRadius: BorderRadius.circular(20),
                  color: Color.fromRGBO(30, 30, 30, 1),
                ),
                child: Padding(
                  padding: const EdgeInsets.only(left: 70, top: 35),
                  child: Column(
                      crossAxisAlignment: CrossAxisAlignment.start,
                      mainAxisSize: MainAxisSize.max,
                      children: [
                        Row(children: [
                          Text(
                            "Zaterdag",
                            style: TextStyle(
                                color: Color.fromRGBO(92, 191, 204, 1),
                                fontSize: 30),
                          ),
                        ]),
                        Row(children: [
                          Text(
                            "Boiler",
                            style: TextStyle(
                                color: Color.fromRGBO(92, 191, 204, 1),
                                fontSize: 20),
                          ),
                          Switch(
                            value: zaterdag_Boiler,
                            onChanged: (bool newValue) {
                              setState(() {
                                zaterdag_Boiler = newValue;
                                einde();
                              });
                            },
                          )
                        ]),
                        Row(children: [
                          Text(
                            "Fornuis",
                            style: TextStyle(
                                color: Color.fromRGBO(92, 191, 204, 1),
                                fontSize: 20),
                          ),
                          Switch(
                            value: zaterdag_Fornuis,
                            onChanged: (bool newValue) {
                              setState(() {
                                zaterdag_Fornuis = newValue;
                                einde();
                              });
                            },
                          )
                        ]),
                        Row(children: [
                          Text(
                            "Lichten",
                            style: TextStyle(
                                color: Color.fromRGBO(92, 191, 204, 1),
                                fontSize: 20),
                          ),
                          Switch(
                            value: zaterdag_Lichten,
                            onChanged: (bool newValue) {
                              setState(() {
                                zaterdag_Lichten = newValue;
                                einde();
                              });
                            },
                          )
                        ]),
                        Row(children: [
                          Text(
                            "Vaatwas",
                            style: TextStyle(
                                color: Color.fromRGBO(92, 191, 204, 1),
                                fontSize: 20),
                          ),
                          Switch(
                            value: zaterdag_Vaatwas,
                            onChanged: (bool newValue) {
                              setState(() {
                                zaterdag_Vaatwas = newValue;
                                einde();
                              });
                            },
                          )
                        ]),
                      ]),
                ),
              ),
              SizedBox(
                height: 30,
              ),
              Container(
                height: 275,
                width: 275,
                alignment: Alignment.center,
                decoration: BoxDecoration(
                  boxShadow: [
                    BoxShadow(
                      color: Colors.grey.withOpacity(0.2),
                      spreadRadius: 5,
                      blurRadius: 7,
                      offset: Offset(0, 3), // changes position of shadow
                    ),
                  ],
                  borderRadius: BorderRadius.circular(20),
                  color: Color.fromRGBO(30, 30, 30, 1),
                ),
                child: Padding(
                  padding: const EdgeInsets.only(left: 70, top: 35),
                  child: Column(
                      crossAxisAlignment: CrossAxisAlignment.start,
                      mainAxisSize: MainAxisSize.max,
                      children: [
                        Row(children: [
                          Text(
                            "Zondag",
                            style: TextStyle(
                                color: Color.fromRGBO(92, 191, 204, 1),
                                fontSize: 30),
                          ),
                        ]),
                        Row(children: [
                          Text(
                            "Boiler",
                            style: TextStyle(
                                color: Color.fromRGBO(92, 191, 204, 1),
                                fontSize: 20),
                          ),
                          Switch(
                            value: zondag_Boiler,
                            onChanged: (bool newValue) {
                              setState(() {
                                zondag_Boiler = newValue;
                                einde();
                              });
                            },
                          )
                        ]),
                        Row(children: [
                          Text(
                            "Fornuis",
                            style: TextStyle(
                                color: Color.fromRGBO(92, 191, 204, 1),
                                fontSize: 20),
                          ),
                          Switch(
                            value: zondag_Fornuis,
                            onChanged: (bool newValue) {
                              setState(() {
                                zondag_Fornuis = newValue;
                                einde();
                              });
                            },
                          )
                        ]),
                        Row(children: [
                          Text(
                            "Lichten",
                            style: TextStyle(
                                color: Color.fromRGBO(92, 191, 204, 1),
                                fontSize: 20),
                          ),
                          Switch(
                            value: zondag_Lichten,
                            onChanged: (bool newValue) {
                              setState(() {
                                zondag_Lichten = newValue;
                                einde();
                              });
                            },
                          )
                        ]),
                        Row(children: [
                          Text(
                            "Vaatwas",
                            style: TextStyle(
                                color: Color.fromRGBO(92, 191, 204, 1),
                                fontSize: 20),
                          ),
                          Switch(
                            value: zondag_Vaatwas,
                            onChanged: (bool newValue) {
                              setState(() {
                                zondag_Vaatwas = newValue;
                                einde();
                              });
                            },
                          )
                        ]),
                      ]),
                ),
              ),
              SizedBox(
                height: 30,
              ),
              Container(
                height: 275,
                width: 275,
                alignment: Alignment.center,
                decoration: BoxDecoration(
                  boxShadow: [
                    BoxShadow(
                      color: Colors.grey.withOpacity(0.2),
                      spreadRadius: 5,
                      blurRadius: 7,
                      offset: Offset(0, 3), // changes position of shadow
                    ),
                  ],
                  borderRadius: BorderRadius.circular(20),
                  color: Color.fromRGBO(30, 30, 30, 1),
                ),
                child: Padding(
                  padding: const EdgeInsets.only(top: 100),
                  child: Column(
                    children: [
                      Text(
                        "Reset weekplanning",
                        style: TextStyle(
                            color: Color.fromRGBO(92, 191, 204, 1),
                            fontSize: 20),
                      ),
                      Switch(
                        value: Reset,
                        onChanged: (bool newValue) {
                          setState(() {
                            Reset = newValue;
                            if (newValue == true) {
                              maandag_Boiler = false;
                              maandag_Fornuis = false;
                              maandag_Lichten = false;
                              maandag_Vaatwas = false;

                              dinsdag_Boiler = false;
                              dinsdag_Fornuis = false;
                              dinsdag_Lichten = false;
                              dinsdag_Vaatwas = false;

                              woensdag_Boiler = false;
                              woensdag_Fornuis = false;
                              woensdag_Lichten = false;
                              woensdag_Vaatwas = false;

                              donderdag_Boiler = false;
                              donderdag_Fornuis = false;
                              donderdag_Lichten = false;
                              donderdag_Vaatwas = false;

                              vrijdag_Boiler = false;
                              vrijdag_Fornuis = false;
                              vrijdag_Lichten = false;
                              vrijdag_Vaatwas = false;

                              zaterdag_Boiler = false;
                              zaterdag_Fornuis = false;
                              zaterdag_Lichten = false;
                              zaterdag_Vaatwas = false;

                              zondag_Boiler = false;
                              zondag_Fornuis = false;
                              zondag_Lichten = false;
                              zondag_Vaatwas = false;
                            }
                            einde();
                          });
                        },
                      ),
                    ],
                  ),
                ),
              ),
              SizedBox(height: 50),
            ],
          ),
        ],
      ),
    );
  }
}
