package net.fishlabs.gof2hdallandroid2012;

import android.content.res.AssetManager;
import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Enumeration;
import java.util.zip.ZipEntry;
import java.util.zip.ZipFile;

/* JADX INFO: loaded from: classes.dex */
public class FMODExtractionHandler {
    private static String FMOD_STAMP_NAME = "fmod_stamp_001.47947";
    private AssetManager assetManager;
    private String externalFilesDir;
    private long fMODSize;
    private String mainOBBFilePath;

    public FMODExtractionHandler(String str, long j, AssetManager assetManager, String str2) {
        this.fMODSize = j;
        this.externalFilesDir = str;
        this.assetManager = assetManager;
        this.mainOBBFilePath = str2;
    }

    private void copyFMODFilesOutOfArchive(String str) throws IOException {
        ZipFile zipFile = new ZipFile(str);
        Enumeration<? extends ZipEntry> enumerationEntries = zipFile.entries();
        byte[] bArr = new byte[16384];
        while (enumerationEntries.hasMoreElements()) {
            ZipEntry zipEntryNextElement = enumerationEntries.nextElement();
            String strSubstring = zipEntryNextElement.getName().substring(zipEntryNextElement.getName().lastIndexOf("/") + 1);
            if (strSubstring.contains("FMOD")) {
                BufferedOutputStream bufferedOutputStream = new BufferedOutputStream(new FileOutputStream(new File(this.externalFilesDir + File.separator, strSubstring)));
                BufferedInputStream bufferedInputStream = new BufferedInputStream(zipFile.getInputStream(zipEntryNextElement));
                while (true) {
                    int i = bufferedInputStream.read(bArr);
                    if (i <= 0) {
                        break;
                    } else {
                        bufferedOutputStream.write(bArr, 0, i);
                    }
                }
                bufferedOutputStream.flush();
                bufferedOutputStream.close();
                bufferedInputStream.close();
            }
        }
        zipFile.close();
    }

    public void extractFMODFiles() throws IOException {
        File file = new File(this.externalFilesDir);
        if (!file.exists()) {
            file.createNewFile();
        }
        if (file.getUsableSpace() < this.fMODSize) {
            throw new IOException("not enough external storage available");
        }
        String[] list = this.assetManager.list("assets/data/audio");
        if (list.length != 0) {
            for (String str : list) {
                InputStream inputStreamOpen = this.assetManager.open("assets/data/audio/" + str);
                FileOutputStream fileOutputStream = new FileOutputStream(file + "/" + str);
                copyFile(inputStreamOpen, fileOutputStream);
                inputStreamOpen.close();
                fileOutputStream.flush();
                fileOutputStream.close();
            }
        } else {
            copyFMODFilesOutOfArchive(this.mainOBBFilePath);
        }
        new File(this.externalFilesDir + File.separator + FMOD_STAMP_NAME).createNewFile();
    }

    private void copyFile(InputStream inputStream, OutputStream outputStream) throws IOException {
        byte[] bArr = new byte[1024];
        while (true) {
            int i = inputStream.read(bArr);
            if (i == -1) {
                return;
            } else {
                outputStream.write(bArr, 0, i);
            }
        }
    }

    public boolean filesAlreadyExtracted() {
        return new File(this.externalFilesDir + File.separator + FMOD_STAMP_NAME).exists();
    }
}
