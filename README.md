# samp-node-encode-fix
 Fix para caracteres ASCII extended en SAMP-NODE.
 `sampctl package install TommS2/samp-node-encode-fix`
 

# Español / Spanish

## Públicas
  Centrandonos más en el problema que tiene samp-node y samp en general, todo recae en que, a la hora de transmitir los caracteres desde Pawn hasta NodeJS el plugin no es capaz que interpretar los caracteres que están fuera de la tabla ASCII convencional. Es por ello que el include llama a tres eventos **que deben ser declarados en nuestro código interpretado por NodeJS**.
  * `OnPlayerTextEx(playerid: number, text: string)`
  * `OnPlayerCommandTextEx(playerid: number, cmdtext: string)`
  * `OnPlayerDialogResponseEx(playerid: number, dialogid: number, response: number, listitem: number, string: string)`
 
  Para que estas funciones puedan ser utilizadas, deberán ser declaradas mediante `samp.registerEvent()`. Ejemplo:
  ```ts
  samp.registerEvent("OnPlayerTextEx", "is")
  samp.on("OnPlayerTextEx", (playerid: number, text: string) => {
      // Your code
      return 1;
  });
  ```

## Funciones
 Con el objetivo de solucionar el problema con los caracteres de nuestro diccionario (tildes, ñ, etcétera) y su impresión en funciones nativas como `SendClientMessage`, `SendClientMessageToAll` o inclusive en `ShowPlayerDialog` se crearon funciones con el mismo nombre pero con finalización en **Ex**.
  * `SendClientMessageEx(playerid: number, color: number, message: string)`
  * `SendClientMessageToAllEx(color: number, message: string)`
  * `ShowPlayerDialog(playerid: number, dialogid: number, style: number, caption: string, info: string, button1: string, button2: string)`
  
  Para ser utilizadas deberán ser llamadas como públicas. Ejemplo:
  ```ts
  samp.on("OnPlayerTextEx", (playerid: number, text: string) => {
      samp.callPublic("SendClientMessageEx", "iis", playerid, -1, `Escribiste: ${text}`);
      return 1;
  });
  ```
  
  ## Créditos
   Se da todo el crédito y agradecimiento a las siguientes personas por sus librerías, que hicieron posible hacer este include.
   * [AmyrAhmady/samp-node](https://github.com/AmyrAhmady/samp-node)
   * [oscar-broman/strlib](https://github.com/oscar-broman/strlib)
   
   
   
# Inglés / English

## Publics
  Focusing more on the problem that samp-node and samp in general have, everything lies in the fact that, when transmitting the characters from Pawn to NodeJS, the plugin is not capable of interpreting the characters that are outside the conventional ASCII table. That is why the include calls three events **that must be declared in our code interpreted by NodeJS**.
  * `OnPlayerTextEx(playerid: number, text: string)`
  * `OnPlayerCommandTextEx(playerid: number, cmdtext: string)`
  * `OnPlayerDialogResponseEx(playerid: number, dialogid: number, response: number, listitem: number, string: string)`
 
  In order for these functions to be used, they must be declared using `samp.registerEvent()`. Example:
  ```ts
  samp.registerEvent("OnPlayerTextEx", "is")
  samp.on("OnPlayerTextEx", (playerid: number, text: string) => {
      // Your code
      return 1;
  });
  ```

## Functions
 In order to solve the problem with the characters from our dictionary (tildes, ñ, etc.) and their printing in native functions such as `SendClientMessage`, `SendClientMessageToAll` or even in `ShowPlayerDialog`, functions with the same name but with ending were created. in **Ex**.
  * `SendClientMessageEx(playerid: number, color: number, message: string)`
  * `SendClientMessageToAllEx(color: number, message: string)`
  * `ShowPlayerDialog(playerid: number, dialogid: number, style: number, caption: string, info: string, button1: string, button2: string)`
  
  To be used they must be called as public. Example:
  ```ts
  samp.on("OnPlayerTextEx", (playerid: number, text: string) => {
      samp.callPublic("SendClientMessageEx", "iis", playerid, -1, `You typed: ${text}`);
      return 1;
  });
  ```
  
  ## Credits
   Full credit and thanks go to the following people for their libraries, which made this include possible.
   * [AmyrAhmady/samp-node](https://github.com/AmyrAhmady/samp-node)
   * [oscar-broman/strlib](https://github.com/oscar-broman/strlib)
