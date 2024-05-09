![](/documents/images/GDD/logo.png)

### Autores

- [Matt Castellanos Silva](https://github.com/MattCastUCM)
- [Pedro León Miranda](https://github.com/P4179)
- [Francisco Mollá Astrar](https://github.com/frmolla)
- [Nanxi Qin](https://github.com/NanxiQin)
- [María Sachez Carrasco](https://github.com/marsache)
- [Rocío Sánchez Horcajuelo López](https://github.com/Bimbloc)
- [Santiago Tienda Perus](https://github.com/Santienper)
- [Laura Wang Qiu](https://github.com/LauraWangQiu)
- [Jianuo Wen](https://github.com/Jjianuo)
- [Likang Wu](https://github.com/likangwu03)

## GDD

### Índice

- [Ficha técnica](#1-ficha-técnica)
- [Descripción](#2-descripción)
- [Jugabilidad](#3-jugabilidad)
  - [Cámara](#31-cámara)
  - [Mecánicas del jugador](#32-mecánicas-del-jugador)
  - [Mecánicas de las bolas](#33-mecánicas-de-las-bolas)
  - [Mecánicas de escenario y objetos](#34-mecánicas-de-escenario-y-objetos)
    - [Objetos](#341-objetos)
    - [PowerUps](#342-powerups)
    - [Otros](#343-otros)
- [Reglas](#4-reglas)
- [HUD](#5-hud)
  - [Mockup del HUD](#51-mockup-del-hud)
  - [Explicación de los elementos del HUD](#52-explicación-de-los-elementos-del-hud)
- [Visual](#6-visual)
- [Menús y flujo de juego](#7-menús-y-flujo-de-juego)
- [Referencias](#8-referencias)
  - [Videojuegos](#81-videojuegos)
  - [Recursos](#82-recursos)
    - [Escenario y personajes](#821-escenario-y-personajes)
    - [UI](#822-ui)
    - [Sonido](#823-sonido)

### 1. Ficha técnica

- **Título:** Billiards adrift
- **Género:** Deporte, arcade
- **Target:** Jugador casual
- **Rating:** Pegi 3
- **Plataforma:** PC
- **Modos de juego:** Un jugador

### 2. Descripción

Este es un juego arcade basado en el billar cuyo objetivo principal es meter todas las bolas en el menor tiempo posible perdiendo el mínimo número de vidas. 
Cada uno de los niveles presenta un mapa distinto con diferentes objetos y enemigos.

### 3. Jugabilidad	

#### 3.1. Cámara

La cámara es fija con una vista cenital y muestra la mesa de billar en su totalidad. Se deja un pequeño margen a los lados para dar espacio al HUD.

#### 3.2. Mecánicas del jugador

| Mecánica | Descripción | Input |
|:--------:|:-----------:|:-----:|
| Golpe con el palo | La fuerza con la que se golpea depende de cuanto se ha echado hacia atrás el palo de la interfaz. | Click izquierdo |
| Colocación del palo | El jugador puede elegir la dirección. El palo apunta en la dirección equivalente al vector que se forma entre la posición del ratón a la posición de la bola blanca. | Movimiento del  ratón |

#### 3.3. Mecánicas de las bolas

| Mecánica | Descripción |
|:--------:|:-----------:|
| Rebote | El ángulo y la velocidad del rebote dependen de la trayectoria y la fuerza que lleva la bola en el momento del impacto con otras bolas o con alguna de las paredes. |
| Bola negra | Esta bola debe introducirse en el hueco contrario a la última bola metida y después de haber metido el resto de bolas. Si se incumple una de estas reglas, se pierde la partida. |
| Bola blanca | Es la bola que golpea el jugador con el palo. Sirve para que choque con el resto de bolas y las mueva. Si se mete en un hueco, se produce una falta. |
| Bolas del resto de colores | El jugador debe meter cada una de las bolas en el hueco de su mismo color para poder terminar el juego. Son lisas. Hay 14 bolas en total. |

#### 3.4. Mecánicas de escenario y objetos

##### 3.4.1. Objetos

| Nombre | Imagen | Descripción |
|:------:|:------:|:-----------:|
| Paredes estáticas |  | No se mueven. Las bolas pueden rebotar contra ellas. Los límites del tablero son también paredes estáticas. |
| Paredes móviles | ![](/documents/images/GDD/movable_wall.png) | Se mueven de un punto a otro en línea recta. Las bolas pueden rebotar contra ellas. |
| Explosivo | ![](/documents/images/GDD/explosive.png) | Objeto en la mesa, solo funciona una vez. Cuando una bola impacta se produce una explosión que repele todas las bolas a su alrededor.  |
| Agujeros de color | ![](/documents/images/GDD/colored_hole.png) | Sólo pueden entrar bolas del mismo color. Se produce una falta si esto no se cumple. |
| Acelerador | ![](/documents/images/GDD/accelerator.png) | Cuando una de las bolas pasa por encima de uno de ellos, aumenta su velocidad. |

##### 3.4.2. PowerUps

| Nombre | Imagen | Forma de conseguirlo | Descripción |
|:------:|:------:|:--------------------:|:-----------:|
| Reloj | ![](/documents/images/GDD/clock_render.png) | Aparece en un lugar aleatorio de la mesa. Se consigue tocando con la bola blanca. | Aumenta el tiempo. |
| Corazón | ![](/documents/images/GDD/heart_render.png) | Aparece en un lugar aleatorio de la mesa. Se consigue tocando con la bola blanca. | Restaura una vida. |

##### 3.4.3. Otros

| Nombre | Imagen | Descripción |
|:------:|:------:|:-----------:|
| Milk & Tea | ![](/documents/images/GDD/milk_tea.png) | Gato que forma parte del escenario. Se le puede ver en uno de los lados de la mesa dando apoyo emocional al jugador. Su boca se abre cada vez que se introduce una bola en uno de los agujeros. **Es meramente decorativo.** |

### 4. Reglas

El objetivo consiste en meter todas las bolas antes de que acabe el tiempo. Cada bola tiene un color y debe meterse en el agujero del mismo color, a excepción de la blanca que es la que se lanza y sirve para golpear al resto de bolas  y la negra, que no se puede meter hasta haber metido el resto de bolas y debe introducirse en el hueco contrario a la última bola metida.
El jugador también tiene un número de vidas, de modo que cuando comete una falta pierde una de ellas. Se puede cometer una falta de una de las maneras siguientes:
- La bola blanca no toca ninguna otra bola tras ser golpeada.
- Una bola (sin incluir ni a la negra ni a la blanca) entra en un color que no le corresponde.
- La bola blanca entra en un hueco.

El jugador pierde la partida si comete una de las siguientes faltas:
- Introduce la bola negra en un agujero antes de haber metido el resto de bolas.
- Una vez metidas todas las bolas, no introduce la bola negra en el hueco contrario en el que ha metido la última bola.
- Se queda sin tiempo.
- Pierde todas las vidas.
- Una vez metidas todas las bolas, si mete la bola negra e inmediatamente después entra la bola blanca.
La puntuación del jugador depende del tiempo y las vidas restantes que le han quedado a la hora de terminar el juego.

### 5. HUD

#### 5.1. Mockup del HUD

<table>
    <thead>
        <tr>
            <th align="center" valign="center"> 
              <image src="/documents/images/GDD/hud_mockup.png" alt="game_flow" width="90%" height="90%">
            </th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td align="center" valign="center"><i> (Los elementos azules no pertenecen al HUD) </i></td>
        </tr>
    </tbody>
</table>

#### 5.2. Explicación de los elementos del HUD

| Nombre | Descripción |
|:------:|:-----------:|
| Vida | El jugador pierde vidas cuando comete una falta. Al perder todas las vidas se resetea el nivel y se debe volver a intentar desde el principio. |
| Tiempo | El jugador dispone de una cantidad limitada de tiempo para terminar el nivel. El tiempo disponible depende del escenario. |
| Interfaz fuerza de golpe | Esta interfaz sirve para elegir la fuerza del golpe. Para ello, se debe hacer click derecho hasta conseguir la potencia deseada. Cuantos más clicks derechos se den, mayor será la potencia del golpe. |
| Dirección bola | La dirección del golpe se elige girando el palo del tablero alrededor de la bola blanca. Se indica con una línea blanca la trayectoria con la que saldría despedida esta bola. |

### 6. Visual

El juego tendrá una estética sobria y casual como resultado de adaptar la estética propia del billar original para cuadrar con los elementos añadidos al juego. Estos elementos son más típicos de una experiencia arcade y acompañan el carácter casual que le caracteriza como minijuego.
A pesar de tener un toque arcade y ser un minijuego se tratará de mantener un aspecto algo elegante.

### 7. Menús y flujo de juego

| Menús |
|:-----:|
| ![](/documents/images/GDD/main_menu_mockup.png) |
| *Menú principal* |
| ![](/documents/images/GDD/controls_menu_mockup.png) |
| *Menú de controles* |
| ![](/documents/images/GDD/rules_menu_mockup.png) |
| *Menú de reglas* |
| ![](/documents/images/GDD/pause_menu_mockup.png) |
| *Menú de pausa* |
| ![](/documents/images/GDD/end_win_menu_mockup.png) |
| *Menú de victoria* |
| ![](/documents/images/GDD/end_lose_menu_mockup.png) |
| *Menú de derrota* |

| Diagrama de flujo de juego |
|:-----:|
| ![](/documents/images/GDD/scenes_graph.png) |

### 8. Referencias	

#### 8.1. Videojuegos

- 8 Ball Pool (Miniclip)

#### 8.2. Recursos

- [Milk & Tea](https://sketchfab.com/3d-models/pop-cat-2d1c8b8514684b0a8d1b8203caa01a95)
- [Heart PowerUp](https://sketchfab.com/3d-models/heartlow-poly-8fa9f20549c74bc99dc209ac795d7ca1)
- [Clock PowerUp](https://www.turbosquid.com/3d-models/alarm-clock-1007895)
- [Pool Table and Balls](https://sketchfab.com/3d-models/billard-f46f4038d27c4bfda52bcac33e478cb0)
- [Billiard Cue](https://sketchfab.com/3d-models/billard-2ee32fdb0e6743ed971f6bc143ca81de)
- [Stool](https://sketchfab.com/3d-models/stool-fR9ctvdd66MHfHQpXgUft4cl1gT)
- [Ground](https://3dtextures.me/2022/05/21/wood-027/)
- [Accelerator](https://www.google.com/search?q=lighting+icon&sca_esv=6bc39e904ccee14e&rlz=1C1CHBF_esES1074ES1074&udm=2&prmd=ivnbz&sxsrf=ADLYWIJYa2OcIKazPLOdjdFuHGLy9H2heQ:1715071884157&source=lnt&tbs=ic:trans&uds=ADvngMgpYEU-_VPft0z-hmM5h-H0BivEGtTadW4kmZWvVC16dYTCBe07oHX2S5VfCVcMsvBnVDtadkFoV3NIXc6bbjlTq0p1O_0BytLzS1vaKblljlzNEYWA8imbuDvnfgKhQC-fSGP0TB3NgiAN9BUjdb2iTl7Ze_3YrxTcp_aLqVpLwPWsuuf2BUJLdNGpCsKXKKwdHIAqkUE8E4tVRroFUsZYc-KBL3nOYj86hYpmzVi_5tJN-GH8D5Q6NQm8EwVgIeDg8TQNTaDkoLaJt65JSobnSY92LQ&sa=X&ved=2ahUKEwjEg63TlPuFAxUWA9sEHYpPDYQQpwV6BAgBEA8&biw=1536&bih=743&dpr=1.25#vhid=zbrCpRMbo-q-7M&vssid=mosaic)
