
char * SSLeay_version(int type)

{
  char *pcVar1;
  
  pcVar1 = "OpenSSL 1.0.1u  22 Sep 2016";
  if (type != 0) {
    if (type == 3) {
      return "built on: Mon Feb 20 03:09:41 2023";
    }
    if (type == 2) {
      return 
      "compiler: gcc -m32 -O3 -I. -I.. -I../include  -DOPENSSL_THREADS -D_REENTRANT -DDSO_DLFCN -DHAVE_DLFCN_H -O3 -fomit-frame-pointer -Wall"
      ;
    }
    if (type != 4) {
      pcVar1 = "OPENSSLDIR: \"/usr/local/openssl101ux86o3\"";
      if (type != 5) {
        pcVar1 = "not available";
      }
      return pcVar1;
    }
    pcVar1 = "platform: linux-generic32";
  }
  return pcVar1;
}

