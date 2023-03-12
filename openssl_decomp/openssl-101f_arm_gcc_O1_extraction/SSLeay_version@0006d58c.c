
char * SSLeay_version(int type)

{
  char *pcVar1;
  
  if (type == 0) {
    return "OpenSSL 1.0.1f 6 Jan 2014";
  }
  if (type == 3) {
    BIO_snprintf(&buf_7881,0x28,"built on: %s","Tue Feb 14 06:45:15 PST 2023");
    return &buf_7881;
  }
  if (type == 2) {
    BIO_snprintf(PTR_buf_7882_0006d620,0xdf,"compiler: %s",
                 "arm-linux-gnueabihf-gcc-4.8 -O1 -DOPENSSL_THREADS -D_REENTRANT -DDSO_DLFCN -DHAVE_DLFCN_H -DTERMIO -O3 -Wall -DOPENSSL_BN_ASM_MONT -DOPENSSL_BN_ASM_GF2m -DSHA1_ASM -DSHA256_ASM -DSHA512_ASM -DAES_ASM -DGHASH_ASM"
                );
    return PTR_buf_7882_0006d620;
  }
  if (type != 4) {
    pcVar1 = "not available";
    if (type == 5) {
      pcVar1 = "OPENSSLDIR: \"/usr/local/openssl\"";
    }
    return pcVar1;
  }
  BIO_snprintf(PTR_buf_7883_0006d624,0x17,"platform: %s","linux-armv4");
  return PTR_buf_7883_0006d624;
}

