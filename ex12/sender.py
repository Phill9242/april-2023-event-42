import smtplib
from email.message import EmailMessage
from email.mime.multipart import MIMEMultipart
from email.mime.base import MIMEBase
from email import encoders

import smtplib
from email.mime.multipart import MIMEMultipart
from email.mime.base import MIMEBase
from email.mime.text import MIMEText
from email.utils import COMMASPACE
from email import encoders

def send_email_with_attachment(smtp_server, smtp_port, sender_email, sender_password, recipient_email, subject, body, attachment_path=None):
    # Crie uma mensagem de email Multipart
    msg = MIMEMultipart()
    msg['Subject'] = subject
    msg['From'] = sender_email
    msg['To'] = recipient_email
    msg.attach(EmailMessage(body))

    # Adicione o anexo, se fornecido
    if attachment_path:
        try:
            with open(attachment_path, 'rb') as attachment_file:
                attachment = MIMEBase('application', 'octet-stream')
                attachment.set_payload(attachment_file.read())
            encoders.encode_base64(attachment)
            attachment.add_header('Content-Disposition', f'attachment; filename={attachment_path}')
            msg.attach(attachment)
        except Exception as e:
            print(f"Erro ao anexar arquivo: {e}")
            return

    # Conecte-se ao servidor SMTP e envie o email
    try:
        with smtplib.SMTP_SSL(smtp_server, smtp_port) as server:
            server.login(sender_email, sender_password)
            server.send_message(msg)
            print("Email enviado com sucesso!")
    except Exception as e:
        print(f"Erro ao enviar o email: {e}")


def read_email_config(file_path):
    config = {}
    with open(file_path, 'r') as file:
        for line in file:
            key, value = line.strip().split('=')
            config[key] = value
    return config

config = read_email_config('email.txt')

subject = config['subject']
body = config['body']
attachment_path = config['attachment_path']
smtp_server = config['smtp_server']
smtp_port = int(config['smtp_port'])
sender_email = config['sender_email']
sender_password = config['sender_password']
recipient_email = config['recipient_email']

send_email_with_attachment(smtp_server, smtp_port, sender_email, sender_password, recipient_email, subject, body, attachment_path)
