package net.fishlabs.gof2hdallandroid2012;

import android.support.v4.view.MotionEventCompat;
import java.util.HashMap;
import java.util.Locale;

/* JADX INFO: loaded from: classes.dex */
public class LocalizationService {
    private static int _fileSizeMB = 950;
    private final HashMap<MessageCodes, String> messages = new HashMap<>();

    public enum Languages {
        chinese,
        english,
        french,
        german,
        italian,
        japanese,
        korean,
        polish,
        portuguese,
        russian,
        spanish
    }

    protected enum MessageCodes {
        LICENCE_NOT_VALID,
        LOAD_CONNECTION_FAILED,
        LOAD_CONNECTION_FAILED_IO,
        LOAD_FILE_ERROR,
        LOAD_NO_MEMORY,
        LOAD_SECURITY_ERROR,
        LOAD_START,
        LOAD_STREAM_ERROR,
        LOAD_SUCCESS,
        LOAD_USER_CANCELED,
        MESSAGE_CANCEL,
        MESSAGE_CONTENT_DOWNLOADED,
        MESSAGE_DAYS,
        MESSAGE_DOWNLOAD_STOPPED,
        MESSAGE_EXTRACTING,
        MESSAGE_HOURS,
        MESSAGE_INFO,
        MESSAGE_LOADING,
        MESSAGE_MINUTES,
        MESSAGE_NO,
        MESSAGE_OVERWRITE,
        MESSAGE_PLEASE_WAIT,
        MESSAGE_PROGRESS,
        MESSAGE_QUIT,
        MESSAGE_SECONDS,
        MESSAGE_TIME_REMAINING,
        MESSAGE_VERIFYING,
        MESSAGE_YES
    }

    public LocalizationService() {
        SetMessages();
    }

    protected Languages GetCountry(String str) {
        if (str.compareTo("DE") == 0) {
            return Languages.german;
        }
        if (str.compareTo("EN") == 0) {
            return Languages.english;
        }
        if (str.compareTo("FR") == 0) {
            return Languages.french;
        }
        if (str.compareTo("ES") == 0) {
            return Languages.spanish;
        }
        if (str.compareTo("IT") == 0) {
            return Languages.italian;
        }
        if (str.compareTo("PL") == 0) {
            return Languages.polish;
        }
        if (str.compareTo("RU") == 0) {
            return Languages.russian;
        }
        if (str.compareTo("ZH") == 0) {
            return Languages.chinese;
        }
        return Languages.english;
    }

    public String getMessages(MessageCodes messageCodes) {
        switch (AnonymousClass1.$SwitchMap$net$fishlabs$gof2hdallandroid2012$LocalizationService$MessageCodes[messageCodes.ordinal()]) {
            case 1:
                return this.messages.get(MessageCodes.LICENCE_NOT_VALID);
            case 2:
                return this.messages.get(MessageCodes.LOAD_CONNECTION_FAILED);
            case 3:
                return this.messages.get(MessageCodes.LOAD_CONNECTION_FAILED_IO);
            case 4:
                return this.messages.get(MessageCodes.LOAD_FILE_ERROR);
            case 5:
                return this.messages.get(MessageCodes.LOAD_NO_MEMORY);
            case 6:
                return this.messages.get(MessageCodes.LOAD_SECURITY_ERROR);
            case 7:
                return this.messages.get(MessageCodes.LOAD_START);
            case 8:
                return this.messages.get(MessageCodes.LOAD_STREAM_ERROR);
            case 9:
                return this.messages.get(MessageCodes.LOAD_SUCCESS);
            case 10:
                return this.messages.get(MessageCodes.LOAD_USER_CANCELED);
            case 11:
                return this.messages.get(MessageCodes.MESSAGE_CANCEL);
            case 12:
                return this.messages.get(MessageCodes.MESSAGE_INFO);
            case 13:
                return this.messages.get(MessageCodes.MESSAGE_LOADING);
            case 14:
                return this.messages.get(MessageCodes.MESSAGE_NO);
            case 15:
                return this.messages.get(MessageCodes.MESSAGE_OVERWRITE);
            case 16:
                return this.messages.get(MessageCodes.MESSAGE_PLEASE_WAIT);
            case 17:
                return this.messages.get(MessageCodes.MESSAGE_QUIT);
            case 18:
                return this.messages.get(MessageCodes.MESSAGE_YES);
            case 19:
                return this.messages.get(MessageCodes.MESSAGE_CONTENT_DOWNLOADED);
            case 20:
                return this.messages.get(MessageCodes.MESSAGE_TIME_REMAINING);
            case MotionEventCompat.AXIS_WHEEL /* 21 */:
                return this.messages.get(MessageCodes.MESSAGE_PROGRESS);
            case MotionEventCompat.AXIS_GAS /* 22 */:
                return this.messages.get(MessageCodes.MESSAGE_DOWNLOAD_STOPPED);
            case MotionEventCompat.AXIS_BRAKE /* 23 */:
                return this.messages.get(MessageCodes.MESSAGE_HOURS);
            case MotionEventCompat.AXIS_DISTANCE /* 24 */:
                return this.messages.get(MessageCodes.MESSAGE_MINUTES);
            case 25:
                return this.messages.get(MessageCodes.MESSAGE_SECONDS);
            case MotionEventCompat.AXIS_SCROLL /* 26 */:
                return this.messages.get(MessageCodes.MESSAGE_DAYS);
            case MotionEventCompat.AXIS_RELATIVE_X /* 27 */:
                return this.messages.get(MessageCodes.MESSAGE_VERIFYING);
            case MotionEventCompat.AXIS_RELATIVE_Y /* 28 */:
                return this.messages.get(MessageCodes.MESSAGE_EXTRACTING);
            default:
                return "null";
        }
    }

    public void SetMessages() {
        switch (GetCountry(Locale.getDefault().getLanguage().toUpperCase())) {
            case german:
                this.messages.put(MessageCodes.LOAD_START, "Für GOF2 werden ca. " + _fileSizeMB + " MB an zusätzlichen Inhalten benötigt. Klicke auf 'Ok' um den Download zu starten. Wir empfehlen eine Wi-Fi-Verbindung.");
                this.messages.put(MessageCodes.LOAD_CONNECTION_FAILED_IO, "Es konnte keine Internetverbindung gefunden werden. Bitte die Einstellungen überprüfen und den Download erneut starten.");
                this.messages.put(MessageCodes.LOAD_CONNECTION_FAILED, "Beim Herunterladen ist ein Netzwerk-Fehler aufgetreten. Bitte erneut versuchen.");
                this.messages.put(MessageCodes.LOAD_NO_MEMORY, "Es ist nicht genügend Speicherplatz vorhanden. Bitte sicherstellen, dass mindestens " + _fileSizeMB + " MB freier Speicher zur Verfügung stehen.");
                this.messages.put(MessageCodes.LOAD_USER_CANCELED, "Der Download wurde abgebrochen.");
                this.messages.put(MessageCodes.LOAD_STREAM_ERROR, "Beim Lesen der Datei ist ein Fehler aufgetreten. Bitte erneut versuchen.");
                this.messages.put(MessageCodes.LOAD_SECURITY_ERROR, "Beim Speichern der Datei ist ein Fehler aufgetreten. Bitte sicherstellen, dass der Datenträger beschreibbar ist.");
                this.messages.put(MessageCodes.LOAD_FILE_ERROR, "Beim Anlegen der Datei ist ein Fehler aufgetreten. Bitte erneut versuchen.");
                this.messages.put(MessageCodes.LICENCE_NOT_VALID, "Diese Version ist nicht lizensiert. Bitte eine gültige Lizenz auf dem Android Market erwerben.");
                this.messages.put(MessageCodes.MESSAGE_QUIT, "Wirklich beenden?");
                this.messages.put(MessageCodes.MESSAGE_YES, "Ja");
                this.messages.put(MessageCodes.MESSAGE_NO, "Nein");
                this.messages.put(MessageCodes.MESSAGE_CANCEL, "Abbrechen");
                this.messages.put(MessageCodes.MESSAGE_LOADING, "Lädt...");
                this.messages.put(MessageCodes.MESSAGE_INFO, "Info");
                this.messages.put(MessageCodes.MESSAGE_PLEASE_WAIT, "Bitte warten...");
                this.messages.put(MessageCodes.MESSAGE_OVERWRITE, "");
                this.messages.put(MessageCodes.MESSAGE_CONTENT_DOWNLOADED, "Daten erfolgreich heruntergeladen!");
                this.messages.put(MessageCodes.MESSAGE_TIME_REMAINING, "Verbleibende Zeit:");
                this.messages.put(MessageCodes.MESSAGE_PROGRESS, "Fortschritt:");
                this.messages.put(MessageCodes.MESSAGE_DOWNLOAD_STOPPED, "Herunterladen gestoppt");
                this.messages.put(MessageCodes.MESSAGE_DAYS, "Tage");
                this.messages.put(MessageCodes.MESSAGE_HOURS, "Stunden");
                this.messages.put(MessageCodes.MESSAGE_MINUTES, "Minuten");
                this.messages.put(MessageCodes.MESSAGE_SECONDS, "Sekunden");
                this.messages.put(MessageCodes.MESSAGE_VERIFYING, "Überprüfen ...");
                this.messages.put(MessageCodes.MESSAGE_EXTRACTING, "Entpacken ...");
                break;
            case english:
                this.messages.put(MessageCodes.LOAD_START, "For GOF2 you will need about " + _fileSizeMB + " MB memory capacity for additional contents. Click “OK” to download. We recommend using a Wi-Fi connection.");
                this.messages.put(MessageCodes.LOAD_CONNECTION_FAILED_IO, "No internet connection could be found. Please check your settings and try downloading again.");
                this.messages.put(MessageCodes.LOAD_CONNECTION_FAILED, "A network error has occurred while downloading. Please try again.");
                this.messages.put(MessageCodes.LOAD_NO_MEMORY, "You don’t seem to have enough memory capacity. Please ensure you have at least " + _fileSizeMB + " MB free memory capacity available.");
                this.messages.put(MessageCodes.LOAD_USER_CANCELED, "The download has been cancelled.");
                this.messages.put(MessageCodes.LOAD_STREAM_ERROR, "A file read error has occurred. Please try again.");
                this.messages.put(MessageCodes.LOAD_SECURITY_ERROR, "An error has occurred while saving the file. Please ensure the data storage device is writeable.");
                this.messages.put(MessageCodes.LOAD_FILE_ERROR, "An error has occurred while creating the file. Please try again.");
                this.messages.put(MessageCodes.LICENCE_NOT_VALID, "This application is not licensed. Please purchase it from Android Market.");
                this.messages.put(MessageCodes.MESSAGE_QUIT, "Are you sure you want to quit?");
                this.messages.put(MessageCodes.MESSAGE_YES, "Yes");
                this.messages.put(MessageCodes.MESSAGE_NO, "No");
                this.messages.put(MessageCodes.MESSAGE_CANCEL, "Cancel");
                this.messages.put(MessageCodes.MESSAGE_LOADING, "Loading...");
                this.messages.put(MessageCodes.MESSAGE_INFO, "Info");
                this.messages.put(MessageCodes.MESSAGE_PLEASE_WAIT, "Please wait...");
                this.messages.put(MessageCodes.MESSAGE_OVERWRITE, "");
                this.messages.put(MessageCodes.MESSAGE_CONTENT_DOWNLOADED, "Data downloaded successfully!");
                this.messages.put(MessageCodes.MESSAGE_TIME_REMAINING, "Time Remaining:");
                this.messages.put(MessageCodes.MESSAGE_PROGRESS, "Progress:");
                this.messages.put(MessageCodes.MESSAGE_DOWNLOAD_STOPPED, "Download stopped");
                this.messages.put(MessageCodes.MESSAGE_DAYS, "days");
                this.messages.put(MessageCodes.MESSAGE_HOURS, "hours");
                this.messages.put(MessageCodes.MESSAGE_MINUTES, "minutes");
                this.messages.put(MessageCodes.MESSAGE_SECONDS, "seconds");
                this.messages.put(MessageCodes.MESSAGE_VERIFYING, "Verifying ...");
                this.messages.put(MessageCodes.MESSAGE_EXTRACTING, "Unzipping ...");
                break;
            case french:
                this.messages.put(MessageCodes.LOAD_START, "Pour GOF2 env. " + _fileSizeMB + " MB de capacités supplémentaires sont exigés. Clique sur OK pour démarrer le téléchargement. Nous recommandons une liaison Wi-Fi.");
                this.messages.put(MessageCodes.LOAD_CONNECTION_FAILED_IO, "Une liaison internet n’a pu avoir lieu. Vérifier svp les paramètres et redémarrer le téléchargement.");
                this.messages.put(MessageCodes.LOAD_CONNECTION_FAILED, "Une erreur de réseau s’est produite lors du téléchargement. Faire un nouvel essai.");
                this.messages.put(MessageCodes.LOAD_NO_MEMORY, "La capacité de mémoire est insuffisante. Assurez-vous que " + _fileSizeMB + " MB de mémoire minimum soient disponibles.");
                this.messages.put(MessageCodes.LOAD_USER_CANCELED, "Le téléchargement a été interrompu.");
                this.messages.put(MessageCodes.LOAD_STREAM_ERROR, "Une erreur s’est produite à la lecture du fichier. Faire un nouvel essai.");
                this.messages.put(MessageCodes.LOAD_SECURITY_ERROR, "Une erreur s’est produite à la sauvegarde du fichier. Assurez-vous svp que le support de données est bien réinscriptible.");
                this.messages.put(MessageCodes.LOAD_FILE_ERROR, "Une erreur s’est produite à la création du fichier. Faire un nouvel essai.");
                this.messages.put(MessageCodes.LICENCE_NOT_VALID, "Cette version n’est pas licenciée. Merci d’acquérir une licence valable sur l’Android Market.");
                this.messages.put(MessageCodes.MESSAGE_QUIT, "Êtes-vous sûr de vouloir quitter ?");
                this.messages.put(MessageCodes.MESSAGE_YES, "Oui");
                this.messages.put(MessageCodes.MESSAGE_NO, "Non");
                this.messages.put(MessageCodes.MESSAGE_CANCEL, "Annuler");
                this.messages.put(MessageCodes.MESSAGE_LOADING, "Chargement...");
                this.messages.put(MessageCodes.MESSAGE_INFO, "Informations");
                this.messages.put(MessageCodes.MESSAGE_PLEASE_WAIT, "Veuillez patienter...");
                this.messages.put(MessageCodes.MESSAGE_OVERWRITE, "");
                this.messages.put(MessageCodes.MESSAGE_CONTENT_DOWNLOADED, "Les données téléchargées avec succès!");
                this.messages.put(MessageCodes.MESSAGE_TIME_REMAINING, "Temps restant:");
                this.messages.put(MessageCodes.MESSAGE_PROGRESS, "Progrès:");
                this.messages.put(MessageCodes.MESSAGE_DOWNLOAD_STOPPED, "Télécharger arrêté");
                this.messages.put(MessageCodes.MESSAGE_DAYS, "jours");
                this.messages.put(MessageCodes.MESSAGE_HOURS, "heures");
                this.messages.put(MessageCodes.MESSAGE_MINUTES, "minutes");
                this.messages.put(MessageCodes.MESSAGE_SECONDS, "secondes");
                this.messages.put(MessageCodes.MESSAGE_VERIFYING, "Vérification ...");
                this.messages.put(MessageCodes.MESSAGE_EXTRACTING, "Décompression ...");
                break;
            case russian:
                this.messages.put(MessageCodes.LOAD_START, "Для GOF2 понадобится прибл. " + _fileSizeMB + " MB дополнительного объема. Нажмите на 'Ok' чтобы начать загрузку файла. Мы рекомендуем соединение по Wi-Fi.");
                this.messages.put(MessageCodes.LOAD_CONNECTION_FAILED_IO, "Соединение с Интернетом не было найдено. Пожалуйста, проверьте настройки и снова начните загрузку.");
                this.messages.put(MessageCodes.LOAD_CONNECTION_FAILED, "При загрузке произошла ошибка сети. Пожалуйста, попробуйте еще раз.");
                this.messages.put(MessageCodes.LOAD_NO_MEMORY, "Нет достаточного места для сохранения файла. Пожалуйста, предоставьте по крайней мере " + _fileSizeMB + " MB свободной памяти.");
                this.messages.put(MessageCodes.LOAD_USER_CANCELED, "Загрузка прервана.");
                this.messages.put(MessageCodes.LOAD_STREAM_ERROR, "При чтении файла произошла ошибка. Пожалуйста, попробуйте еще раз.");
                this.messages.put(MessageCodes.LOAD_SECURITY_ERROR, "При сохранении файла произошла ошибка. Пожалуйста, убедитесь в том, что носитель информации допускает запись.");
                this.messages.put(MessageCodes.LOAD_FILE_ERROR, "При размещении файла произошла ошибка. Пожалуйста, попробуйте еще раз.");
                this.messages.put(MessageCodes.LICENCE_NOT_VALID, "Данное версия игры не имеет лицензии. Приобретите действительную лицензию на Android Market.");
                this.messages.put(MessageCodes.MESSAGE_QUIT, "Вы действительно хотите выйти из игры?");
                this.messages.put(MessageCodes.MESSAGE_YES, "Да");
                this.messages.put(MessageCodes.MESSAGE_NO, "Нет");
                this.messages.put(MessageCodes.MESSAGE_CANCEL, "Отмена");
                this.messages.put(MessageCodes.MESSAGE_LOADING, "Загрузка...");
                this.messages.put(MessageCodes.MESSAGE_INFO, "Информация");
                this.messages.put(MessageCodes.MESSAGE_PLEASE_WAIT, "Пожалуйста, подождите...");
                this.messages.put(MessageCodes.MESSAGE_OVERWRITE, "");
                this.messages.put(MessageCodes.MESSAGE_CONTENT_DOWNLOADED, "Данные, загруженные успешно!");
                this.messages.put(MessageCodes.MESSAGE_TIME_REMAINING, "Оставшееся время:");
                this.messages.put(MessageCodes.MESSAGE_PROGRESS, "Прогресс:");
                this.messages.put(MessageCodes.MESSAGE_DOWNLOAD_STOPPED, "Скачать остановился");
                this.messages.put(MessageCodes.MESSAGE_DAYS, "дни");
                this.messages.put(MessageCodes.MESSAGE_HOURS, "часы");
                this.messages.put(MessageCodes.MESSAGE_MINUTES, "минуты");
                this.messages.put(MessageCodes.MESSAGE_SECONDS, "секунды");
                this.messages.put(MessageCodes.MESSAGE_VERIFYING, "Проверка ...");
                this.messages.put(MessageCodes.MESSAGE_EXTRACTING, "Разархивирование ...");
                break;
            case spanish:
                this.messages.put(MessageCodes.LOAD_START, "Para GOF2 se requieren aprox. " + _fileSizeMB + " MB para contenidos adicionales. Haz clic en 'Ok' para iniciar la descarga. Recomendamos una conexión Wi-Fi.");
                this.messages.put(MessageCodes.LOAD_CONNECTION_FAILED_IO, "No se ha encontrado ninguna conexión a Internet. Por favor, comprueba las preferencias e intenta de nuevo realizar la descarga.");
                this.messages.put(MessageCodes.LOAD_CONNECTION_FAILED, "Se ha producido un error de red durante la descarga. Por favor, inténtalo de nuevo.");
                this.messages.put(MessageCodes.LOAD_NO_MEMORY, "No dispones de suficiente espacio en el disco. Por favor, asegúrate de disponer al menos de " + _fileSizeMB + " MB libres.");
                this.messages.put(MessageCodes.LOAD_USER_CANCELED, "Se ha cancelado la descarga.");
                this.messages.put(MessageCodes.LOAD_STREAM_ERROR, "Se ha producido un error durante la lectura del archivo. Por favor, inténtalo de nuevo.");
                this.messages.put(MessageCodes.LOAD_SECURITY_ERROR, "Se ha producido un error mientras se intentaba guardar el archivo. Por favor, asegúrate de que el dispositivo de almacenamiento de datos sea grabable. ");
                this.messages.put(MessageCodes.LOAD_FILE_ERROR, "Se ha producido un error mientras se intentaba crear el archivo. Por favor, inténtalo de nuevo.");
                this.messages.put(MessageCodes.LICENCE_NOT_VALID, "No dispone de licencia para esta versión. Por favor, adquiera una licencia válida en el Android Market.");
                this.messages.put(MessageCodes.MESSAGE_QUIT, "¿Estás seguro de que deseas salir?");
                this.messages.put(MessageCodes.MESSAGE_YES, "Si");
                this.messages.put(MessageCodes.MESSAGE_NO, "No");
                this.messages.put(MessageCodes.MESSAGE_CANCEL, "Cancelar");
                this.messages.put(MessageCodes.MESSAGE_LOADING, "Cargando...");
                this.messages.put(MessageCodes.MESSAGE_INFO, "Info");
                this.messages.put(MessageCodes.MESSAGE_PLEASE_WAIT, "Por favor aguarde...");
                this.messages.put(MessageCodes.MESSAGE_OVERWRITE, "");
                this.messages.put(MessageCodes.MESSAGE_CONTENT_DOWNLOADED, "Datos descargados con éxito!");
                this.messages.put(MessageCodes.MESSAGE_TIME_REMAINING, "Tiempo restante:");
                this.messages.put(MessageCodes.MESSAGE_PROGRESS, "Progreso:");
                this.messages.put(MessageCodes.MESSAGE_DOWNLOAD_STOPPED, "Descargar detenido");
                this.messages.put(MessageCodes.MESSAGE_DAYS, "días");
                this.messages.put(MessageCodes.MESSAGE_HOURS, "horas");
                this.messages.put(MessageCodes.MESSAGE_MINUTES, "minutos");
                this.messages.put(MessageCodes.MESSAGE_SECONDS, "segundos");
                this.messages.put(MessageCodes.MESSAGE_VERIFYING, "Verificación ...");
                this.messages.put(MessageCodes.MESSAGE_EXTRACTING, "Descomprimir ...");
                break;
            case italian:
                this.messages.put(MessageCodes.LOAD_START, "Per GOF2 sono necessari ca. " + _fileSizeMB + " MB per contenuti aggiuntivi. Cliccare su 'Ok' per avviare il download. Consigliamo una connessione Wi-Fi.");
                this.messages.put(MessageCodes.LOAD_CONNECTION_FAILED_IO, "Non è stato trovato alcun collegamento internet. Si prega di controllare le impostazioni e di riavviare nuovamente il download.");
                this.messages.put(MessageCodes.LOAD_CONNECTION_FAILED, "Durante il download si è verificato un errore di rete. Si prega di riprovare.");
                this.messages.put(MessageCodes.LOAD_NO_MEMORY, "Non vi è sufficiente spazio su disco disponibile. Si prega di assicurarsi che vi siano almeno " + _fileSizeMB + " MB di memoria libera a disposizione.");
                this.messages.put(MessageCodes.LOAD_USER_CANCELED, "Il download è stato interrotto.");
                this.messages.put(MessageCodes.LOAD_STREAM_ERROR, "Durante la lettura del file si è verificato un errore. Si prega di riprovare.");
                this.messages.put(MessageCodes.LOAD_SECURITY_ERROR, "Durante il salvataggio del file si è verificato un errore. Si prega di assicurarsi che il disco sia scrivibile. ");
                this.messages.put(MessageCodes.LOAD_FILE_ERROR, "Durante la creazione del file si è verificato un errore. Si prega di riprovare.");
                this.messages.put(MessageCodes.LICENCE_NOT_VALID, "Questa versione non è concessa in licenza. Acquistare una licenza valida sul Mercato Android.");
                this.messages.put(MessageCodes.MESSAGE_QUIT, "Sei sicuro di voler uscire?");
                this.messages.put(MessageCodes.MESSAGE_YES, "Sì");
                this.messages.put(MessageCodes.MESSAGE_NO, "No");
                this.messages.put(MessageCodes.MESSAGE_CANCEL, "Cancella");
                this.messages.put(MessageCodes.MESSAGE_LOADING, "Caricamento...");
                this.messages.put(MessageCodes.MESSAGE_INFO, "Informazioni");
                this.messages.put(MessageCodes.MESSAGE_PLEASE_WAIT, "Attendere...");
                this.messages.put(MessageCodes.MESSAGE_OVERWRITE, "");
                this.messages.put(MessageCodes.MESSAGE_CONTENT_DOWNLOADED, "Dati scaricati con successo!");
                this.messages.put(MessageCodes.MESSAGE_TIME_REMAINING, "Tempo rimanente:");
                this.messages.put(MessageCodes.MESSAGE_PROGRESS, "Progresso:");
                this.messages.put(MessageCodes.MESSAGE_DOWNLOAD_STOPPED, "Scarica fermato");
                this.messages.put(MessageCodes.MESSAGE_DAYS, "giorni");
                this.messages.put(MessageCodes.MESSAGE_HOURS, "ore");
                this.messages.put(MessageCodes.MESSAGE_MINUTES, "minuti");
                this.messages.put(MessageCodes.MESSAGE_SECONDS, "secondi");
                this.messages.put(MessageCodes.MESSAGE_VERIFYING, "Verifica ...");
                this.messages.put(MessageCodes.MESSAGE_EXTRACTING, "Decompressione ...");
                break;
            case polish:
                this.messages.put(MessageCodes.LOAD_START, "Do GOF2 potrzebne jest ok. " + _fileSizeMB + " MB na dodatkową zawartość. Kliknij na 'OK', aby rozpocząć pobieranie. Polecamy połączenie Wi-Fi.");
                this.messages.put(MessageCodes.LOAD_CONNECTION_FAILED_IO, "Nie znaleziono żadnego połączenia. Prosimy o sprawdzenie ustawień i ponowne rozpoczęcie pobierania. ");
                this.messages.put(MessageCodes.LOAD_CONNECTION_FAILED, "Przy pobieraniu pojawił się błąd sieci. Prosimy spróbować ponownie.");
                this.messages.put(MessageCodes.LOAD_NO_MEMORY, "Na dysku nie ma wystarczającej ilości wolnego miejsca. Prosimy o sprawdzenie, czy na dysku znajduje się co najmniej " + _fileSizeMB + " MB wolnego miejsca.");
                this.messages.put(MessageCodes.LOAD_USER_CANCELED, "Pobieranie zostało przerwane.");
                this.messages.put(MessageCodes.LOAD_STREAM_ERROR, "Podczas wczytywania pliku pojawił się błąd. Prosimy spróbować ponownie. ");
                this.messages.put(MessageCodes.LOAD_SECURITY_ERROR, "Podczas zapisywania pliku pojawił się błąd. Prosimy o sprawdzenie, czy na nośniku można zapisywać dane. ");
                this.messages.put(MessageCodes.LOAD_FILE_ERROR, "Podczas tworzenia danych pojawił się błąd. Prosimy spróbować ponownie.");
                this.messages.put(MessageCodes.LICENCE_NOT_VALID, "Aktualna wersja nie jest licencjonowana. Ważna licencja jest dostępna w Android Market.");
                this.messages.put(MessageCodes.MESSAGE_QUIT, "Czy na pewno chcesz wyjść?");
                this.messages.put(MessageCodes.MESSAGE_YES, "Tak");
                this.messages.put(MessageCodes.MESSAGE_NO, "Nie");
                this.messages.put(MessageCodes.MESSAGE_CANCEL, "Anuluj");
                this.messages.put(MessageCodes.MESSAGE_LOADING, "Ładowanie...");
                this.messages.put(MessageCodes.MESSAGE_INFO, "Informacje");
                this.messages.put(MessageCodes.MESSAGE_PLEASE_WAIT, "Proszę czekać...");
                this.messages.put(MessageCodes.MESSAGE_OVERWRITE, "");
                this.messages.put(MessageCodes.MESSAGE_CONTENT_DOWNLOADED, "Dane wczytane z powodzeniem!");
                this.messages.put(MessageCodes.MESSAGE_TIME_REMAINING, "Pozostały czas:");
                this.messages.put(MessageCodes.MESSAGE_PROGRESS, "Postęp:");
                this.messages.put(MessageCodes.MESSAGE_DOWNLOAD_STOPPED, "Pobierz zatrzymał");
                this.messages.put(MessageCodes.MESSAGE_DAYS, "dni");
                this.messages.put(MessageCodes.MESSAGE_HOURS, "godziny");
                this.messages.put(MessageCodes.MESSAGE_MINUTES, "minuty");
                this.messages.put(MessageCodes.MESSAGE_SECONDS, "sekundy");
                this.messages.put(MessageCodes.MESSAGE_VERIFYING, "Weryfikacja ...");
                this.messages.put(MessageCodes.MESSAGE_EXTRACTING, "Rozpakowaniu ...    ");
                break;
            case chinese:
                this.messages.put(MessageCodes.LOAD_START, "《超级竞速》需要大约 " + _fileSizeMB + " MB的储存空间。请按「OK」，以进行下载。我们建议你使用Wi-Fi网络。");
                this.messages.put(MessageCodes.LOAD_CONNECTION_FAILED_IO, "找不到网络。请检查设定，并重新下载。");
                this.messages.put(MessageCodes.LOAD_CONNECTION_FAILED, "在下载过程中，遇到网络出错。请重新尝试。");
                this.messages.put(MessageCodes.LOAD_NO_MEMORY, "没有足够的储存空间。请确定装置最少有 " + _fileSizeMB + " MB的可用储存空间。");
                this.messages.put(MessageCodes.LOAD_USER_CANCELED, "下载已被取消。");
                this.messages.put(MessageCodes.LOAD_STREAM_ERROR, "在读存资料时发生错误，请重新尝试。");
                this.messages.put(MessageCodes.LOAD_SECURITY_ERROR, "在储存资料时发生错误，请重新尝试。");
                this.messages.put(MessageCodes.LOAD_FILE_ERROR, "在创建资料时发生错误，请重新尝试。");
                this.messages.put(MessageCodes.LICENCE_NOT_VALID, "这版本并没有注册，请到Android Market购买有效的版本。");
                this.messages.put(MessageCodes.MESSAGE_QUIT, "确定终止？");
                this.messages.put(MessageCodes.MESSAGE_YES, "是");
                this.messages.put(MessageCodes.MESSAGE_NO, "否");
                this.messages.put(MessageCodes.MESSAGE_CANCEL, "取消");
                this.messages.put(MessageCodes.MESSAGE_LOADING, "读取中…");
                this.messages.put(MessageCodes.MESSAGE_INFO, "信息");
                this.messages.put(MessageCodes.MESSAGE_PLEASE_WAIT, "请等候…");
                this.messages.put(MessageCodes.MESSAGE_OVERWRITE, "");
                this.messages.put(MessageCodes.MESSAGE_CONTENT_DOWNLOADED, "资料已成功下载！");
                this.messages.put(MessageCodes.MESSAGE_TIME_REMAINING, "尚需时间：");
                this.messages.put(MessageCodes.MESSAGE_PROGRESS, "进度：");
                this.messages.put(MessageCodes.MESSAGE_DOWNLOAD_STOPPED, "下载已经停止");
                this.messages.put(MessageCodes.MESSAGE_DAYS, "日");
                this.messages.put(MessageCodes.MESSAGE_HOURS, "小时");
                this.messages.put(MessageCodes.MESSAGE_MINUTES, "分钟");
                this.messages.put(MessageCodes.MESSAGE_SECONDS, "秒");
                this.messages.put(MessageCodes.MESSAGE_VERIFYING, "核对中…");
                this.messages.put(MessageCodes.MESSAGE_EXTRACTING, "解压中…");
                break;
            default:
                this.messages.put(MessageCodes.LOAD_START, "For GOF2 you will need about " + _fileSizeMB + " MB memory capacity for additional contents. Click “OK” to download. We recommend using a Wi-Fi connection.");
                this.messages.put(MessageCodes.LOAD_CONNECTION_FAILED_IO, "No internet connection could be found. Please check your settings and try downloading again.");
                this.messages.put(MessageCodes.LOAD_CONNECTION_FAILED, "A network error has occurred while downloading. Please try again.");
                this.messages.put(MessageCodes.LOAD_NO_MEMORY, "You don’t seem to have enough memory capacity. Please ensure you have at least " + _fileSizeMB + " MB free memory capacity available.");
                this.messages.put(MessageCodes.LOAD_USER_CANCELED, "The download has been cancelled.");
                this.messages.put(MessageCodes.LOAD_STREAM_ERROR, "A file read error has occurred. Please try again.");
                this.messages.put(MessageCodes.LOAD_SECURITY_ERROR, "An error has occurred while saving the file. Please ensure the data storage device is writeable.");
                this.messages.put(MessageCodes.LOAD_FILE_ERROR, "An error has occurred while creating the file. Please try again.");
                this.messages.put(MessageCodes.LICENCE_NOT_VALID, "This application is not licensed. Please purchase it from Android Market.");
                this.messages.put(MessageCodes.MESSAGE_QUIT, "Are you sure you want to quit?");
                this.messages.put(MessageCodes.MESSAGE_YES, "Yes");
                this.messages.put(MessageCodes.MESSAGE_NO, "No");
                this.messages.put(MessageCodes.MESSAGE_CANCEL, "Cancel");
                this.messages.put(MessageCodes.MESSAGE_LOADING, "Loading...");
                this.messages.put(MessageCodes.MESSAGE_INFO, "Info");
                this.messages.put(MessageCodes.MESSAGE_PLEASE_WAIT, "Please wait...");
                this.messages.put(MessageCodes.MESSAGE_OVERWRITE, "");
                this.messages.put(MessageCodes.MESSAGE_CONTENT_DOWNLOADED, "Data downloaded successfully!");
                this.messages.put(MessageCodes.MESSAGE_TIME_REMAINING, "Time Remaining:");
                this.messages.put(MessageCodes.MESSAGE_PROGRESS, "Progress:");
                this.messages.put(MessageCodes.MESSAGE_DOWNLOAD_STOPPED, "Download stopped");
                this.messages.put(MessageCodes.MESSAGE_DAYS, "days");
                this.messages.put(MessageCodes.MESSAGE_HOURS, "hours");
                this.messages.put(MessageCodes.MESSAGE_MINUTES, "minutes");
                this.messages.put(MessageCodes.MESSAGE_SECONDS, "seconds");
                this.messages.put(MessageCodes.MESSAGE_VERIFYING, "Verifying ...");
                this.messages.put(MessageCodes.MESSAGE_EXTRACTING, "Unzipping ...");
                break;
        }
    }

    /* JADX INFO: renamed from: net.fishlabs.gof2hdallandroid2012.LocalizationService$1, reason: invalid class name */
    static /* synthetic */ class AnonymousClass1 {
        static final /* synthetic */ int[] $SwitchMap$net$fishlabs$gof2hdallandroid2012$LocalizationService$MessageCodes;

        static {
            try {
                $SwitchMap$net$fishlabs$gof2hdallandroid2012$LocalizationService$Languages[Languages.german.ordinal()] = 1;
            } catch (NoSuchFieldError unused) {
            }
            try {
                $SwitchMap$net$fishlabs$gof2hdallandroid2012$LocalizationService$Languages[Languages.english.ordinal()] = 2;
            } catch (NoSuchFieldError unused2) {
            }
            try {
                $SwitchMap$net$fishlabs$gof2hdallandroid2012$LocalizationService$Languages[Languages.french.ordinal()] = 3;
            } catch (NoSuchFieldError unused3) {
            }
            try {
                $SwitchMap$net$fishlabs$gof2hdallandroid2012$LocalizationService$Languages[Languages.russian.ordinal()] = 4;
            } catch (NoSuchFieldError unused4) {
            }
            try {
                $SwitchMap$net$fishlabs$gof2hdallandroid2012$LocalizationService$Languages[Languages.spanish.ordinal()] = 5;
            } catch (NoSuchFieldError unused5) {
            }
            try {
                $SwitchMap$net$fishlabs$gof2hdallandroid2012$LocalizationService$Languages[Languages.italian.ordinal()] = 6;
            } catch (NoSuchFieldError unused6) {
            }
            try {
                $SwitchMap$net$fishlabs$gof2hdallandroid2012$LocalizationService$Languages[Languages.polish.ordinal()] = 7;
            } catch (NoSuchFieldError unused7) {
            }
            try {
                $SwitchMap$net$fishlabs$gof2hdallandroid2012$LocalizationService$Languages[Languages.chinese.ordinal()] = 8;
            } catch (NoSuchFieldError unused8) {
            }
            $SwitchMap$net$fishlabs$gof2hdallandroid2012$LocalizationService$MessageCodes = new int[MessageCodes.values().length];
            try {
                $SwitchMap$net$fishlabs$gof2hdallandroid2012$LocalizationService$MessageCodes[MessageCodes.LICENCE_NOT_VALID.ordinal()] = 1;
            } catch (NoSuchFieldError unused9) {
            }
            try {
                $SwitchMap$net$fishlabs$gof2hdallandroid2012$LocalizationService$MessageCodes[MessageCodes.LOAD_CONNECTION_FAILED.ordinal()] = 2;
            } catch (NoSuchFieldError unused10) {
            }
            try {
                $SwitchMap$net$fishlabs$gof2hdallandroid2012$LocalizationService$MessageCodes[MessageCodes.LOAD_CONNECTION_FAILED_IO.ordinal()] = 3;
            } catch (NoSuchFieldError unused11) {
            }
            try {
                $SwitchMap$net$fishlabs$gof2hdallandroid2012$LocalizationService$MessageCodes[MessageCodes.LOAD_FILE_ERROR.ordinal()] = 4;
            } catch (NoSuchFieldError unused12) {
            }
            try {
                $SwitchMap$net$fishlabs$gof2hdallandroid2012$LocalizationService$MessageCodes[MessageCodes.LOAD_NO_MEMORY.ordinal()] = 5;
            } catch (NoSuchFieldError unused13) {
            }
            try {
                $SwitchMap$net$fishlabs$gof2hdallandroid2012$LocalizationService$MessageCodes[MessageCodes.LOAD_SECURITY_ERROR.ordinal()] = 6;
            } catch (NoSuchFieldError unused14) {
            }
            try {
                $SwitchMap$net$fishlabs$gof2hdallandroid2012$LocalizationService$MessageCodes[MessageCodes.LOAD_START.ordinal()] = 7;
            } catch (NoSuchFieldError unused15) {
            }
            try {
                $SwitchMap$net$fishlabs$gof2hdallandroid2012$LocalizationService$MessageCodes[MessageCodes.LOAD_STREAM_ERROR.ordinal()] = 8;
            } catch (NoSuchFieldError unused16) {
            }
            try {
                $SwitchMap$net$fishlabs$gof2hdallandroid2012$LocalizationService$MessageCodes[MessageCodes.LOAD_SUCCESS.ordinal()] = 9;
            } catch (NoSuchFieldError unused17) {
            }
            try {
                $SwitchMap$net$fishlabs$gof2hdallandroid2012$LocalizationService$MessageCodes[MessageCodes.LOAD_USER_CANCELED.ordinal()] = 10;
            } catch (NoSuchFieldError unused18) {
            }
            try {
                $SwitchMap$net$fishlabs$gof2hdallandroid2012$LocalizationService$MessageCodes[MessageCodes.MESSAGE_CANCEL.ordinal()] = 11;
            } catch (NoSuchFieldError unused19) {
            }
            try {
                $SwitchMap$net$fishlabs$gof2hdallandroid2012$LocalizationService$MessageCodes[MessageCodes.MESSAGE_INFO.ordinal()] = 12;
            } catch (NoSuchFieldError unused20) {
            }
            try {
                $SwitchMap$net$fishlabs$gof2hdallandroid2012$LocalizationService$MessageCodes[MessageCodes.MESSAGE_LOADING.ordinal()] = 13;
            } catch (NoSuchFieldError unused21) {
            }
            try {
                $SwitchMap$net$fishlabs$gof2hdallandroid2012$LocalizationService$MessageCodes[MessageCodes.MESSAGE_NO.ordinal()] = 14;
            } catch (NoSuchFieldError unused22) {
            }
            try {
                $SwitchMap$net$fishlabs$gof2hdallandroid2012$LocalizationService$MessageCodes[MessageCodes.MESSAGE_OVERWRITE.ordinal()] = 15;
            } catch (NoSuchFieldError unused23) {
            }
            try {
                $SwitchMap$net$fishlabs$gof2hdallandroid2012$LocalizationService$MessageCodes[MessageCodes.MESSAGE_PLEASE_WAIT.ordinal()] = 16;
            } catch (NoSuchFieldError unused24) {
            }
            try {
                $SwitchMap$net$fishlabs$gof2hdallandroid2012$LocalizationService$MessageCodes[MessageCodes.MESSAGE_QUIT.ordinal()] = 17;
            } catch (NoSuchFieldError unused25) {
            }
            try {
                $SwitchMap$net$fishlabs$gof2hdallandroid2012$LocalizationService$MessageCodes[MessageCodes.MESSAGE_YES.ordinal()] = 18;
            } catch (NoSuchFieldError unused26) {
            }
            try {
                $SwitchMap$net$fishlabs$gof2hdallandroid2012$LocalizationService$MessageCodes[MessageCodes.MESSAGE_CONTENT_DOWNLOADED.ordinal()] = 19;
            } catch (NoSuchFieldError unused27) {
            }
            try {
                $SwitchMap$net$fishlabs$gof2hdallandroid2012$LocalizationService$MessageCodes[MessageCodes.MESSAGE_TIME_REMAINING.ordinal()] = 20;
            } catch (NoSuchFieldError unused28) {
            }
            try {
                $SwitchMap$net$fishlabs$gof2hdallandroid2012$LocalizationService$MessageCodes[MessageCodes.MESSAGE_PROGRESS.ordinal()] = 21;
            } catch (NoSuchFieldError unused29) {
            }
            try {
                $SwitchMap$net$fishlabs$gof2hdallandroid2012$LocalizationService$MessageCodes[MessageCodes.MESSAGE_DOWNLOAD_STOPPED.ordinal()] = 22;
            } catch (NoSuchFieldError unused30) {
            }
            try {
                $SwitchMap$net$fishlabs$gof2hdallandroid2012$LocalizationService$MessageCodes[MessageCodes.MESSAGE_HOURS.ordinal()] = 23;
            } catch (NoSuchFieldError unused31) {
            }
            try {
                $SwitchMap$net$fishlabs$gof2hdallandroid2012$LocalizationService$MessageCodes[MessageCodes.MESSAGE_MINUTES.ordinal()] = 24;
            } catch (NoSuchFieldError unused32) {
            }
            try {
                $SwitchMap$net$fishlabs$gof2hdallandroid2012$LocalizationService$MessageCodes[MessageCodes.MESSAGE_SECONDS.ordinal()] = 25;
            } catch (NoSuchFieldError unused33) {
            }
            try {
                $SwitchMap$net$fishlabs$gof2hdallandroid2012$LocalizationService$MessageCodes[MessageCodes.MESSAGE_DAYS.ordinal()] = 26;
            } catch (NoSuchFieldError unused34) {
            }
            try {
                $SwitchMap$net$fishlabs$gof2hdallandroid2012$LocalizationService$MessageCodes[MessageCodes.MESSAGE_VERIFYING.ordinal()] = 27;
            } catch (NoSuchFieldError unused35) {
            }
            try {
                $SwitchMap$net$fishlabs$gof2hdallandroid2012$LocalizationService$MessageCodes[MessageCodes.MESSAGE_EXTRACTING.ordinal()] = 28;
            } catch (NoSuchFieldError unused36) {
            }
        }
    }
}
