# Réalisation-d-un-système-de-traitement-audio-temps-réel
Travail réalisé par Meriam Bani et Khalil Rezgui, encadré par M.Khaled Jelassi
Conception des systèmes temps Réel.
Titre du projet: Réalisation d’un système de traitement audio temps réel


Description du Projet
Application embarquée démontrant le traitement audio en temps réel sur carte
STM32F429 Discovery avec architecture multi tâches FreeRTOS Le système capture
l'audio via I2S, applique un gain configurable et calcule une moyenne
des valeurs absoluesL'interface graphique TouchGFX permet de visualiser l amplitude audio
en temps réel et d ajuster le gaindynamiquement


Matériel

Carte STM32F429I DISC1
MCU STM32F429ZIT6 ARM Cortex M4F @ 180 MHz
Affichage LCD TFT 2 4 pouces ILI9341 240x320 pixels RGB565
Audio Codec CS43L22 via I2S3 full duplex
Mémoire 8 MB SDRAM externe
Interface Écran tactile résistif STMPE811


Architecture Logicielle

Tâches FreeRTOS
1 AudioTxTask Haute priorité Traitement audio temps réel
Applique le gain sur les échantillons audio
Met à jour audioSample valeur instantanée
Envoie les données vers la file d attente

2 AverageTask Priorité normale Calcul de moyenne glissante
Calcule la moyenne des 16 dernières valeurs absolues
Met à jour audioSampleAvg enveloppe du signal
Utilisé pour affichage de l amplitude

3 GUI_Task Priorité normale Interface TouchGFX
Affichage graphique sur LCD avec jauge d amplitude
Gestion des interactions tactiles
Contrôle du gain audio via slider

4 defaultTask Priorité normale Tâche d arrière plan


Communication Inter Tâches
Queue Transfert d échantillons audio 4 éléments 2 octets chacun
Mutex Protection des variables partagées audioSample audioSampleAvg
Thread Flags Synchronisation DMA half buffer et full buffer complete


Configuration Audio
Fréquence d échantillonnage 16 kHz
Format I2S Philips 16 bits étendus
Taille de buffer 256 échantillons latence environ 16 ms
Mode Full duplex avec DMA
Fenêtre de moyenne 16 échantillons pour enveloppe


Variables Partagées
volatile int16_t audioSample       Échantillon instantané
volatile int16_t audioSampleAvg    Moyenne glissante enveloppe
volatile float audioGain           Gain audio par défaut 1 0
volatile uint32_t audioSampleCount Compteur d échantillons

Interface TouchGFX
Fonction gainChange
Ajuste le gain audio de 0 à 20x
Formule audioGain = value / 5
Mise à jour en temps réel

Fonction handleTickEvent
Appelée périodiquement par TouchGFX
Récupère audioSampleAvg pour affichage
Met à jour la jauge d amplitude gauge1

PINOUT:

SD:	AMP: WHITE PC12  | MIC: Yellow PC11
CK:	AMP: YELLOW PC10 | MIC: Green
WC:	AMP: BROWN PA15  | MIC: White

Présentation du projet :
[Télécharger la présentation du projet PDF](https://drive.google.com/file/d/1axY-0xhUZbiNkC-MA0SR_Trt3Dp-M0p4/view?usp=sharing)

Vidéo démonstrative : 
[Télécharger la présentation du projet mp4](https://drive.google.com/file/d/1mRoKEGFJSNc03kaejlf5y1Sq1hyqYkiH/view?usp=sharing)
