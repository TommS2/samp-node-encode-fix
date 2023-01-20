#if defined SAMP_NODE_ENCODE_FIX
	#endinput
#endif
#define SAMP_NODE_ENCODE_FIX

#include <a_samp>
#include <samp-node>
#include <strlib>

#if defined _ALS_SendClientMessage
	#undef SendClientMessage
#else
	#define _ALS_SendClientMessage
#endif
#define SendClientMessage SendClientMessageEx

forward SendClientMessageEx(playerid, color, const message[]);
public SendClientMessageEx(playerid, color, const message[]){
	new string[1024];
	utf8decode(string, message);
	SendClientMessage(playerid, color, string);
}

#if defined _ALS_ShowPlayerDialog
	#undef ShowPlayerDialog
#else
	#define _ALS_ShowPlayerDialog
#endif
#define ShowPlayerDialog ShowPlayerDialogEx

new infostring[4096];
forward ShowPlayerDialogEx(playerid, dialogid, style, const caption[], const info[], const button1[], const button2[]);
public ShowPlayerDialogEx(playerid, dialogid, style, const caption[], const info[], const button1[], const button2[]) {
	new captionstring[1024], button1string[1024], button2string[1024];
	format(infostring, sizeof infostring, "");
	utf8decode(infostring, info);
	utf8decode(captionstring, caption);
	utf8decode(button1string, button1);
	utf8decode(button2string, button2);
	ShowPlayerDialog(playerid, dialogid, style, captionstring, infostring, button1string, button2string);
}

#if defined _ALS_SendClientMessageToAll
	#undef SendClientMessageToAll
#else
	#define _ALS_SendClientMessageToAll
#endif
#define SendClientMessageToAll SendClientMessageToAllEx

forward SendClientMessageToAllEx(color, const message[]);
public SendClientMessageToAllEx(color, const message[]){
	new string[1024];
	utf8decode(string, message);
	SendClientMessageToAll(color, string);
	return 1;
}

public OnPlayerCommandText(playerid, cmdtext[]){
	new string[1024];
	utf8encode(string, cmdtext);
	SAMPNode_CallEvent("OnPlayerCommandTextEx", playerid, string);
	return 1;
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]) {
	new string[1024];
	utf8encode(string, inputtext);
	SAMPNode_CallEvent("OnDialogResponseEx", playerid, dialogid, response, listitem, string);
	return 1;
}

public OnPlayerText(playerid, text[]) {
	new string[1024];
	utf8encode(string, text);
	SAMPNode_CallEvent("OnPlayerTextEx", playerid, string);
	return 0;
}