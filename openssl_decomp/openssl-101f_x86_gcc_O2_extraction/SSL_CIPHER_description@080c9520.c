
char * SSL_CIPHER_description(SSL_CIPHER *param_1,char *buf,int size)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  char cVar6;
  uint uVar7;
  char *pcVar8;
  char *pcVar9;
  char *pcVar10;
  char *pcVar11;
  char *pcVar12;
  bool bVar13;
  char *local_34;
  int local_2c;
  
  uVar1 = param_1->algorithm_mac;
  uVar2 = param_1->algorithm_auth;
  uVar3 = param_1->algorithm_mkey;
  uVar4 = param_1->algorithm_ssl;
  uVar5 = param_1->algorithm_enc;
  uVar7 = param_1->algo_strength & 2;
  bVar13 = (param_1->algo_strength & 8) == 0;
  if (bVar13) {
    local_2c = 0x400;
    cVar6 = (uVar5 == 1) + '\a';
  }
  else {
    local_2c = 0x200;
    cVar6 = '\x05';
  }
  local_34 = "SSLv2";
  pcVar11 = " export";
  if (uVar7 == 0) {
    pcVar11 = "";
  }
  if ((((uVar4 & 1) == 0) && (local_34 = "SSLv3", (uVar4 & 2) == 0)) &&
     (local_34 = "TLSv1.2", (uVar4 & 4) == 0)) {
    local_34 = "unknown";
  }
  if (uVar3 == 0x10) {
    pcVar10 = "KRB5";
  }
  else if (uVar3 < 0x11) {
    pcVar10 = "DH/RSA";
    if (uVar3 != 2) {
      if (uVar3 < 3) {
        if (uVar3 != 1) goto LAB_080c986a;
        pcVar10 = "RSA";
        if ((uVar7 != 0) && (pcVar10 = "RSA(1024)", local_2c == 0x200)) {
          pcVar10 = "RSA(512)";
        }
      }
      else {
        pcVar10 = "DH/DSS";
        if (uVar3 != 4) {
          if (uVar3 != 8) goto LAB_080c986a;
          pcVar10 = "DH";
          if ((uVar7 != 0) && (pcVar10 = "DH(1024)", local_2c == 0x200)) {
            pcVar10 = "DH(512)";
          }
        }
      }
    }
  }
  else if (uVar3 == 0x80) {
    pcVar10 = "ECDH";
  }
  else if (uVar3 < 0x81) {
    pcVar10 = "ECDH/RSA";
    if (uVar3 != 0x20) {
      if (uVar3 != 0x40) goto LAB_080c986a;
      pcVar10 = "ECDH/ECDSA";
    }
  }
  else {
    pcVar10 = "PSK";
    if ((uVar3 != 0x100) && (pcVar10 = "SRP", uVar3 != 0x400)) {
LAB_080c986a:
      pcVar10 = "unknown";
    }
  }
  if (uVar2 == 8) {
    pcVar12 = "DH";
  }
  else if (uVar2 < 9) {
    pcVar12 = "DSS";
    if (((uVar2 != 2) && (pcVar12 = "None", uVar2 != 4)) && (pcVar12 = "RSA", uVar2 != 1))
    goto LAB_080c983a;
  }
  else {
    pcVar12 = "KRB5";
    if (uVar2 != 0x20) {
      if (uVar2 < 0x21) {
        pcVar12 = "ECDH";
        if (uVar2 != 0x10) goto LAB_080c983a;
      }
      else {
        pcVar12 = "ECDSA";
        if ((uVar2 != 0x40) && (pcVar12 = "PSK", uVar2 != 0x80)) {
LAB_080c983a:
          pcVar12 = "unknown";
        }
      }
    }
  }
  if (uVar5 == 0x40) {
    pcVar9 = "AES(128)";
  }
  else if (uVar5 < 0x41) {
    if (uVar5 == 4) {
      if (uVar7 == 0) {
        pcVar9 = "RC4(128)";
        if ((param_1->algorithm2 & 2) != 0) {
          pcVar9 = "RC4(64)";
        }
      }
      else {
        pcVar9 = "RC4(56)";
        if (cVar6 == '\x05') {
          pcVar9 = "RC4(40)";
        }
      }
    }
    else if (uVar5 < 5) {
      if (uVar5 == 1) {
        if ((uVar7 == 0) || (pcVar9 = "DES(40)", bVar13)) {
          pcVar9 = "DES(56)";
        }
      }
      else {
        pcVar9 = "3DES(168)";
        if (uVar5 != 2) goto LAB_080c966b;
      }
    }
    else {
      pcVar9 = "IDEA(128)";
      if ((uVar5 != 0x10) && (pcVar9 = "None", uVar5 != 0x20)) {
        if (uVar5 != 8) goto LAB_080c966b;
        pcVar9 = "RC2(128)";
        if ((uVar7 != 0) && (pcVar9 = "RC2(56)", cVar6 == '\x05')) {
          pcVar9 = "RC2(40)";
        }
      }
    }
  }
  else if (uVar5 == 0x200) {
    pcVar9 = "Camellia(256)";
  }
  else if (uVar5 < 0x201) {
    pcVar9 = "AES(256)";
    if ((uVar5 != 0x80) && (pcVar9 = "Camellia(128)", uVar5 != 0x100)) goto LAB_080c966b;
  }
  else {
    pcVar9 = "AESGCM(128)";
    if ((uVar5 != 0x1000) &&
       ((pcVar9 = "AESGCM(256)", uVar5 != 0x2000 && (pcVar9 = "SEED(128)", uVar5 != 0x800)))) {
LAB_080c966b:
      pcVar9 = "unknown";
    }
  }
  if (uVar1 == 0x10) {
    pcVar8 = "SHA256";
  }
  else {
    if (uVar1 < 0x11) {
      pcVar8 = "MD5";
      if ((uVar1 == 1) || (pcVar8 = "SHA1", uVar1 == 2)) goto LAB_080c96a0;
    }
    else {
      pcVar8 = "SHA384";
      if ((uVar1 == 0x20) || (pcVar8 = "AEAD", uVar1 == 0x40)) goto LAB_080c96a0;
    }
    pcVar8 = "unknown";
  }
LAB_080c96a0:
  if (buf == (char *)0x0) {
    buf = (char *)CRYPTO_malloc(0x80,"ssl_ciph.c",0x6ac);
    if (buf == (char *)0x0) {
      return "OPENSSL_malloc Error";
    }
    size = 0x80;
  }
  else if (size < 0x80) {
    return "Buffer too small";
  }
  BIO_snprintf(buf,size,"%-23s %s Kx=%-8s Au=%-4s Enc=%-9s Mac=%-4s%s\n",param_1->name,local_34,
               pcVar10,pcVar12,pcVar9,pcVar8,pcVar11);
  return buf;
}

