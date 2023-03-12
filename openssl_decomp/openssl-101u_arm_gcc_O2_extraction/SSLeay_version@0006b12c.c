
char * SSLeay_version(int type)

{
  char *pcVar1;
  
  if (type == 0) {
    return "OpenSSL 1.0.1u  22 Sep 2016";
  }
  if (type == 3) {
    return "built on: Tue Feb 14 07:33:58 2023";
  }
  if (type == 2) {
    return 
    "compiler: arm-linux-gnueabihf-gcc-4.8 -O2 -I. -I.. -I../include  -DOPENSSL_THREADS -D_REENTRANT -DDSO_DLFCN -DHAVE_DLFCN_H -O3 -Wall -DOPENSSL_BN_ASM_MONT -DOPENSSL_BN_ASM_GF2m -DSHA1_ASM -DSHA256_ASM -DSHA512_ASM -DAES_ASM -DGHASH_ASM"
    ;
  }
  if (type != 4) {
    pcVar1 = "not available";
    if (type == 5) {
      pcVar1 = "OPENSSLDIR: \"/usr/local/openssl101uo2\"";
    }
    return pcVar1;
  }
  return "platform: linux-armv4";
}

