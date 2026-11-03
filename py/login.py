import customtkinter
from PIL import Image


customtkinter.set_appearance_mode("dark")
customtkinter.set_default_color_theme("dark-blue")

janela = customtkinter.CTk()
janela.geometry("700x400")
janela.title("Sistema de login")
janela.resizable(False, False)

foto = customtkinter.CTkImage(
    Image.open("./assets/logo.png"),
    size=(120, 120)
)

img = customtkinter.CTkLabel(
    janela,
    image=foto,
    text=""

)

img.pack(pady=20)

janela.mainloop()