
char * SSLeay_version(int type)

{
  char *pcVar1;
  
  if (type != 0) {
    if (type == 3) {
      (*(code *)PTR_BIO_snprintf_006a8060)
                (buf_5247,0x28,"built on: %s","Tue Feb 14 08:05:51 PST 2023",&_gp);
      pcVar1 = buf_5247;
    }
    else if (type == 2) {
      (*(code *)PTR_BIO_snprintf_006a8060)
                (buf_5248,0x6e,"compiler: %s",
                 " -DOPENSSL_THREADS -D_REENTRANT -DDSO_DLFCN -DHAVE_DLFCN_H -DTERMIO -O3 -fomit-frame-pointer -Wall"
                 ,&_gp);
      pcVar1 = buf_5248;
    }
    else if (type == 4) {
      (*(code *)PTR_BIO_snprintf_006a8060)(buf_5249,0x1b,"platform: %s","linux-generic32");
      pcVar1 = buf_5249;
    }
    else if (type == 5) {
      pcVar1 = "OPENSSLDIR: \"/usr/local/openssl101fmipso0\"";
    }
    else {
      pcVar1 = "not available";
    }
    return pcVar1;
  }
  return "OpenSSL 1.0.1f 6 Jan 2014";
}

