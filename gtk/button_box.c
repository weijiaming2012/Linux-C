#include<gtk/gtk.h>

/*anniuxiangying*/
void click_button(GtkWidget *widget,gpointer *data)
{
	g_print("%s ",(char *)data);
	if(GTK_TOGGLE_BUTTON(widget)->active)
	{
		g_print("state is active\n");
	}
	else
	{
		g_print("state is not active\n");
	}
}

void destroy(GtkWidget *widget,gpointer *data)
{
	gtk_main_quit();
}

int main(int argc,char **argv)
{
	GtkWidget *window;
	GtkWidget *box;
	GSList *group;
	GtkWidget *check,*radio;

	gtk_init(&argc,&argv);
	
	window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	g_signal_connect(GTK_OBJECT(window),"destroy",
					GTK_SIGNAL_FUNC(destroy),NULL);
	gtk_container_border_width(GTK_CONTAINER(window),50);

	/*vbox*/
	box=gtk_vbox_new(FALSE,0);
	gtk_container_add(GTK_CONTAINER(window),box);

	/*two check button*/
	check=gtk_check_button_new_with_label("coffee");
	g_signal_connect(GTK_OBJECT(check),"clicked",
					GTK_SIGNAL_FUNC(click_button),"check button1");
	gtk_box_pack_start(GTK_BOX(box),check,TRUE,TRUE,0);
	gtk_widget_show(check);

	check=gtk_check_button_new_with_label("tea");
	g_signal_connect(GTK_OBJECT(check),"checked",
					GTK_SIGNAL_FUNC(click_button),"check button2");
	gtk_box_pack_start(GTK_BOX(box),check,TRUE,TRUE,0);
	gtk_widget_show(check);

	/*three radio button*/
	radio=gtk_radio_button_new_with_label(NULL,"Apple");
	g_signal_connect(GTK_OBJECT(radio),"clicked",
					GTK_SIGNAL_FUNC(click_button),"Apple");
	gtk_box_pack_start(GTK_BOX(box),radio,TRUE,TRUE,0);
	gtk_widget_show(radio);

	group=gtk_radio_button_group(GTK_RADIO_BUTTON(radio));
	radio=gtk_radio_button_new_with_label(group,"Banana");
	g_signal_connect(GTK_OBJECT(radio),"clicked",
					GTK_SIGNAL_FUNC(click_button),"Banana");
	gtk_box_pack_start(GTK_BOX(box),radio,TRUE,TRUE,0);
	gtk_widget_show(radio);

	group=gtk_radio_button_group(GTK_RADIO_BUTTON(radio));
	radio=gtk_radio_button_new_with_label(group,"Orange");
	g_signal_connect(GTK_OBJECT(radio),"clicked",
					GTK_SIGNAL_FUNC(click_button),"Orange");
	gtk_box_pack_start(GTK_BOX(box),radio,TRUE,TRUE,0);
	gtk_widget_show(radio);

	gtk_widget_show(box);
	gtk_widget_show(window);

	gtk_main();

	return 0;
}
