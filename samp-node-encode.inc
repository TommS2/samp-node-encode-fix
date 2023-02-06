#if defined SAMP_NODE_ENCODE_FIX
	#endinput
#endif
#define SAMP_NODE_ENCODE_FIX

#if !defined isnull
    #define isnull(%1) ((!(%1[0])) || (((%1[0]) == '\1') && (!(%1[1]))))
#endif

#include <a_samp>
#include <samp-node>
#include <strlib>
#include <DialogCenter>
#include <streamer>

forward SendClientMessageEx(playerid, color, const message[]);
public SendClientMessageEx(playerid, color, const message[]){
	new string[1024];
	utf8decode(string, message);
	SendClientMessage(playerid, color, string);
}

new infostring[4096];
forward ShowPlayerDialogEx(playerid, dialogid, style, const caption[], const info[], const button1[], const button2[]);
public ShowPlayerDialogEx(playerid, dialogid, style, const caption[], const info[], const button1[], const button2[]) {
	new captionstring[64], button1string[64], button2string[64];
	utf8decode(infostring, info);
	utf8decode(captionstring, caption);		
	utf8decode(button1string, button1);
	if(!isnull(button2)) {
		utf8decode(button2string, button2);
	}
	dcenter_ShowPlayerDialog(playerid, dialogid, style, captionstring, infostring, button1string, button2string);
}

forward SendClientMessageToAllEx(color, const message[]);
public SendClientMessageToAllEx(color, const message[]){
	new string[1024];
	utf8decode(string, message);
	SendClientMessageToAll(color, string);
	return 1;
}

forward CreateDynamic3DTextLabelFix(const text[], color, Float:x, Float:y, Float:z, Float:drawdistance, attachedplayer, attachedvehicle, testlos, worldid, interiorid, playerid, streamdistance, areaid, priority);
public CreateDynamic3DTextLabelFix(const text[], color, Float:x, Float:y, Float:z, Float:drawdistance, attachedplayer, attachedvehicle , testlos, worldid, interiorid, playerid, streamdistance, areaid, priority){
	new string[1024];
	utf8decode(string, text);
	CreateDynamic3DTextLabel(string, color, x, y, z, drawdistance, attachedplayer, attachedvehicle, testlos, worldid, interiorid, playerid, streamdistance, areaid, priority);
	return 1;
}

forward UpdateDynamic3DTextLabelTextFix(Text3D:id, color, const text[]);
public UpdateDynamic3DTextLabelTextFix(Text3D:id, color, const text[]){
	new string[1024];
	utf8decode(string, text);
	UpdateDynamic3DTextLabelText(id, color, string);
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
