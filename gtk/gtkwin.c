#include<gtk/gtk.h>

/*function*/
void hello(GtkWidget *widget,gpointer *data)
{
	g_print("button clicked and data=%s\n",(char*)data);
}

/*function*/
void destroy(GtkWidget *widget,gpointer *data)
{
	gtk_main_quit();
}

int main(int argc,char **argv)
{
	/*kong jian*/
	GtkWidget *window;
	GtkWidget *button;

	/*chu shi hua*/
	gtk_init(&argc,&argv);

	/*chuangjianchuangkou*/
	window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	g_signal_connect(GTK_OBJECT(window),"destroy",
					GTK_SIGNAL_FUNC(destroy),NULL);
	
	/*shezhichuangkou*/
	gtk_container_border_width(GTK_CONTAINER(window),100);

	/*chuangjiananniu*/
	button=gtk_button_new_with_label("Hello World!");
	g_signal_connect(GTK_OBJECT(button),"clicked",
						GTK_SIGNAL_FUNC(hello),"I am from button");

	/*add button*/
	gtk_container_add(GTK_CONTAINER(window),button);
	/*display window*/
	gtk_widget_show(button);
	gtk_widget_show(window);

	/*xiaoxixunhuan*/
	gtk_main();

	return 0;

}
