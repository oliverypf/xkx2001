//Cracked by Roath
// Room: /d/beijing/west/shibanlu3.c

inherit ROOM;

void create()
{
	set("short", "ʯ��·");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "westup" : __DIR__"danbiqiao",
  "east" : __DIR__"dongtianmen",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}