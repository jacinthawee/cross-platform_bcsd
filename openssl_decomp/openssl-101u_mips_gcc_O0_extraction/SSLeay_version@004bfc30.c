
char * SSLeay_version(int type)

{
  if (type == 0) {
    return "OpenSSL 1.0.1u  22 Sep 2016";
  }
  if (type == 3) {
    return "built on: Tue Feb 14 08:26:10 2023";
  }
  if (type == 2) {
    return 
    "compiler: mips-linux-gnu-gcc-5 -O0 -I. -I.. -I../include  -DOPENSSL_THREADS -D_REENTRANT -DDSO_DLFCN -DHAVE_DLFCN_H -O3 -fomit-frame-pointer -Wall"
    ;
  }
  if (type != 4) {
    if (type != 5) {
      return "not available";
    }
    return "OPENSSLDIR: \"/usr/local/openssl101umipso0\"";
  }
  return "platform: linux-generic32";
}

