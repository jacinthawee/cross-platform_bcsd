
char * SSLeay_version(int type)

{
  char *pcVar1;
  
  pcVar1 = "OpenSSL 1.0.1f 6 Jan 2014";
  if (type != 0) {
    if (type == 3) {
      BIO_snprintf(buf_5227,0x28,"built on: %s","Mon Feb 20 03:19:26 PST 2023");
      pcVar1 = buf_5227;
    }
    else if (type == 2) {
      BIO_snprintf(buf_5228,0x7a,"compiler: %s",
                   "gcc -m32 -O1 -DOPENSSL_THREADS -D_REENTRANT -DDSO_DLFCN -DHAVE_DLFCN_H -DTERMIO -O3 -fomit-frame-pointer -Wall"
                  );
      pcVar1 = buf_5228;
    }
    else if (type == 4) {
      BIO_snprintf(buf_5229,0x1b,"platform: %s","linux-generic32");
      pcVar1 = buf_5229;
    }
    else {
      pcVar1 = "OPENSSLDIR: \"/usr/local/openssl101fx86o1\"";
      if (type != 5) {
        pcVar1 = "not available";
      }
    }
  }
  return pcVar1;
}

