//Cracked by Roath
// yugajing0.c

inherit ITEM;

string* titles = ({
	"������",
	"���Ͼ�",
	"���Ͼ�",
	"������",
//	"���������ܶ��ľ�",
//	"������;�",
//	"��վ�",
//	"�����Ӿ�",
});

void create()
{
	set_name(titles[random(sizeof(titles))], ({ "shu", "maha jing", "book" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ���˷𾭡�\n");
		set("value", 200);
		set("material", "paper");
		set("skill", ([
			"name":	"mahayana",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost":	20,	// jing cost every time study this
			"difficulty":	10,	// the base int to learn this skill
			"max_skill":	50	// the maximum level you can learn
		]) );
	}
}