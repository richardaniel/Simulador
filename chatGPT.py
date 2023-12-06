import openai
import tkinter as tk
from tkinter import messagebox, scrolledtext
from rich import print
from rich.table import Table

openai.api_key = "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"

window = tk.Tk()
window.title("AI Simulador")

# Configuración del estilo de la ventana
window.configure(bg="#F5F5F5")  # Color de fondo
window.geometry("1280x720")  # Tamaño de la ventana
window.resizable(False, False)  # No se puede cambiar el tamaño

table = Table(title="Comandos")
table.add_column("Comando")
table.add_column("Descripción")
table.add_row("exit", "Salir de la aplicación")
table.add_row("new", "Crear una nueva conversación")

# Crear una etiqueta de título con estilo
title_label = tk.Label(window, text="IA Simulador", font=("Arial", 16, "bold"), bg="#F5F5F5")
title_label.pack(pady=20)

# Crear una etiqueta para la tabla
#table_label = tk.Label(window, text=table, justify="left", font=("Courier New", 10), bg="#F5F5F5")


# Contexto del asistente
context = {"role": "system", "content": "Eres un asistente muy útil."}
messages = [context]

def send_message():
    content = entry.get()
    entry.delete(0, tk.END)

    if content == "exit":
        exit = messagebox.askyesno("Salir", "¿Estás seguro?")
        if exit:
            messagebox.showinfo("Adiós", "¡Hasta luego!")
            window.destroy()
        return

    if content == "new":
        messagebox.showinfo("Nueva conversación", "Nueva conversación creada")
        messages.clear()
        messages.append(context)
        return

    messages.append({"role": "user", "content": content})

    response = openai.ChatCompletion.create(model="gpt-3.5-turbo", messages=messages)
    response_content = response.choices[0].message.content

    messages.append({"role": "assistant", "content": response_content})

    response_text.tag_configure("response", justify="left")  # Justificar el texto
    response_text.insert(tk.END, f"> {response_content}\n", "response")  # Agregar espacio después de la respuesta
    response_text.insert(tk.END, "\n")  # Agregar espacio adicional

    response_text.see(tk.END)  # Desplazar automáticamente hacia abajo

# Crear un campo de entrada de texto con estilo
entry = tk.Entry(window, font=("Arial", 12),width=150, justify="left", bg="#FFFFFF", bd=0, insertbackground="#000000", highlightthickness=0, relief=tk.FLAT)
entry.pack(pady=20)

# Crear un botón de envío con estilo
button = tk.Button(window, text="Enviar", command=send_message, font=("Arial", 12), bg="#4CAF50", fg="white")
button.pack()

# Crear un cuadro de texto para mostrar la respuesta del asistente con estilo y capacidad de desplazamiento
response_text = scrolledtext.ScrolledText(window, font=("Arial", 12), bg="#FFFFFF")
response_text.pack(pady=20, fill=tk.BOTH, expand=True)

# Centrar la ventana en la pantalla
window.update_idletasks()
width = window.winfo_width()
height = window.winfo_height()
x = (window.winfo_screenwidth() // 2) - (width // 2)
y = (window.winfo_screenheight() // 2) - (height // 2)
window.geometry(f"{width}x{height}+{x}+{y}")

window.mainloop()
