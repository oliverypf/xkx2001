//Cracked by Roath
// sanqingdian.c �����
// by Marz@11/10/96 
// xQin 8/00

#include <ansi.h>

inherit ROOM;

int burnt, start_burn; 
int is_burning();
int look_an();

void create()
{
	set("short", "�����");
	set("long", @LONG
���������������������䵱�ɻ�͵ĵص㡣����Ԫʼ����̫�ϵ�
���������Ͼ����������м��Ǹ�����Ĵ��㰸(an)����ǽ���ż���̫ʦ�Σ�
���Ϸ��ż������š��������������ȣ�����������Ĺ㳡���ϱ��Ǻ�Ժ��
LONG
	);
	set("valid_startroom", 1);
	
	set("exits", ([
		"north" : __DIR__"dating",
		"south" : __DIR__"hd_zoulang",
	//	"east" : __DIR__"donglang1",
		//"west" : __DIR__"xilang1",
	]));
	
	set("objects", ([
		CLASS_D("wudang") + "/guxu" : 1,
		CLASS_D("wudang") + "/song" : 1]));
		
	set("item_desc", ([
		"an" : (: look_an :),
	]));


	set("cost", 1);
	setup();

	burnt = 0;
	call_out("burn", 120, 1);

//	replace_program(ROOM);
	call_other("/clone/board/wudang_b", "???");
}

void init()
{
	add_action("do_jing", "jing");
}

int is_buring()
{
	return (burnt < 3);
}	

string look_an()
{
	
	switch (burnt) {
	case 0:
		return(HIC"�㰸�Ϲ��������ϵ���𣬷ҷ����á�\n"NOR);
		break;
	case 1:
		return(HIC"�㰸���������ƣ�����յ�������\n"NOR);
		break;
	case 2:
		return(HIC"�㰸�ϵ�����Ѿ����˴�룬�������̣�������Ϣ��\n"NOR);
		break;
	default:
		return(HIY"�㰸��ֻʣ��һ���̻ң��������˾�(jing)����𣡣�\n"NOR);
		break;
	}
	
}  // end of look_an

void burn(int phase)
{
	burnt = phase;
	
	if (burnt < 3) call_out("burn", 120, phase + 1);

} // end of burn


int do_jing(string arg)
{
	object obj, me;
	
	if ( !objectp(me = this_player()) ) return 0;	
	
	if (!arg ) return notify_fail("��Ҫ��ʲô��\n");  
					
	if( !objectp(obj = present(arg, me)) )
		return notify_fail("������û������������\n");
	           
	if ( obj->query("id") != "incense" 
	 ||  obj->is_character() ) return notify_fail("ֻ�ܾ��㣡\n");  
	
	burnt = 0;
	remove_call_out("burn");
	call_out("burn", 120, 1);
	
	message_vision(HIC"$N�ó�һ"+obj->query("unit")+obj->query("name")
		+"�����������ز����㰸�ϡ�\n"NOR, me);
		
	if (me->query("age") < 20 && me->query("wudang/offerring") < 60)
	me->add("wudang/offerring", 2);
	if (me->query("age") < 30 && me->query("wudang/offerring") < 120)
        me->add("wudang/offerring", 2);
	if (me->query("age") > 30 && me->query("wudang/offerring") < 150)
	me->add("wudang/offerring", 2);	                                         		                              		

	destruct(obj);
	
	return 1;		
}

// End of File