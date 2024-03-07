#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>

// Function to read the contents of a file
char* read_file(const char* filename) {
    char* buffer = NULL;
    long length;
    FILE* f = fopen(filename, "rb");
    if (f) {
        fseek(f, 0, SEEK_END);
        length = ftell(f);
        fseek(f, 0, SEEK_SET);
        buffer = malloc(length + 1);
        if (buffer) {
            fread(buffer, 1, length, f);
        }
        fclose(f);
        buffer[length] = '\0';
    }
    return buffer;
}

int main(int argc, char *argv[]) {
    GtkWidget *window;
    gtk_init(&argc, &argv);

    // Create the main window
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "JSON Reader");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Read the file repos.json
    char *filename = "repos.json";
    char *json_data = read_file(filename);
    if (json_data == NULL) {
        g_print("Error reading file: %s\n", filename);
        return 1;
    }

    // Print the content of the file
    printf("Contents of %s:\n%s\n", filename, json_data);

    // Free allocated memory
    free(json_data);

    // Show the window
    gtk_widget_show(window);

    // Start the GTK main loop
    gtk_main();

    return 0;
}
