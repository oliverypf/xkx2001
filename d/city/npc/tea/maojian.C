//Cracked by Roath
// xQin 6/00

inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("����ϸë��", ({ "dujun ximaojian","maojian","cha" }));
        set_weight(1000);
        if( clonep() )
            set_default_object(__FILE__);
        else {
        set("long",
"����һ������ϸë�⣬��ѿ���ڱ��ף��׺�����ˮ�У���ɫ����������Ʒ����������������\n");
                set("unit", "��");
                set("value", 30);
                set("max_liquid", 10);
        }
        set("liquid", ([
            "name" : "����ϸë��",
            "remaining" : 8,
                "type" : "water"
        ]) );
        set("liquid_type", "water");
        setup();
}

