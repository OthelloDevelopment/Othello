/* 八皇后问题测试程序 othello_test.c*/
#include <stdlib.h>
#include <gtk/gtk.h>
#include "othello.h"

//八皇后控件的“Othello”信号的回调函数
static void win(GtkWidget *othello, gpointer data) {
    othello_clear(OTHELLO(othello));//清除棋盘中的皇后
}

int main(int argc, char *argv[]) {
    GtkWidget *window, *vbox, *hbox;
    GtkWidget *label, *image, *statusbar;
    GtkWidget *othello;
    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "黑白棋");

    g_signal_connect(G_OBJECT(window), "delete_event", G_CALLBACK(gtk_main_quit), NULL);
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

    vbox = gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    hbox = gtk_hbox_new(FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 3);

    image = gtk_image_new_from_stock(GTK_STOCK_HELP, GTK_ICON_SIZE_BUTTON);
    gtk_box_pack_start(GTK_BOX(hbox), image, FALSE, FALSE, 3);

    label = gtk_label_new("这是黑白棋的客户端程序");
    gtk_box_pack_start(GTK_BOX(hbox), label, FALSE, FALSE, 3);

    othello = othello_new();
    gtk_box_pack_start(GTK_BOX(vbox), othello, FALSE, FALSE, 3);

    //向自定义控件连接信号"Othello"
    g_signal_connect(G_OBJECT(othello), "Othello", G_CALLBACK(win), NULL);

    statusbar = gtk_statusbar_new();
    gtk_box_pack_start(GTK_BOX(vbox), statusbar, FALSE, FALSE, 3);
    gtk_statusbar_push(statusbar, 1, "");
    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}