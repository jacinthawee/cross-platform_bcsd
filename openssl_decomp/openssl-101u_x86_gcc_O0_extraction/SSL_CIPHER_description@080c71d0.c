
char * SSL_CIPHER_description(SSL_CIPHER *param_1,char *buf,int size)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  char cVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  uint uVar10;
  char *pcVar11;
  bool bVar12;
  char *local_38;
  int local_2c;
  
  uVar1 = param_1->algorithm_ssl;
  uVar2 = param_1->algorithm_mkey;
  uVar3 = param_1->algorithm_auth;
  uVar4 = param_1->algorithm_enc;
  uVar10 = param_1->algo_strength & 2;
  bVar12 = (param_1->algo_strength & 8) == 0;
  if (bVar12) {
    local_2c = 0x400;
    cVar5 = (uVar4 == 1) + '\a';
  }
  else {
    local_2c = 0x200;
    cVar5 = '\x05';
  }
  pcVar8 = " export";
  if (uVar10 == 0) {
    pcVar8 = "";
  }
  pcVar9 = "SSLv2";
  if ((((uVar1 & 1) == 0) && (pcVar9 = "SSLv3", (uVar1 & 2) == 0)) &&
     (pcVar9 = "unknown", (uVar1 & 4) != 0)) {
    pcVar9 = "TLSv1.2";
  }
  if (uVar2 == 0x20) {
    local_38 = "ECDH/RSA";
  }
  else if (uVar2 < 0x21) {
    if (uVar2 == 4) {
      local_38 = "DH/DSS";
    }
    else if (uVar2 < 5) {
      if (uVar2 == 1) {
        local_38 = "RSA";
        if ((uVar10 != 0) && (local_38 = "RSA(512)", local_2c != 0x200)) {
          local_38 = "RSA(1024)";
        }
      }
      else {
        local_38 = "DH/RSA";
        if (uVar2 != 2) goto LAB_080c7393;
      }
    }
    else if (uVar2 == 8) {
      local_38 = "DH";
      if ((uVar10 != 0) && (local_38 = "DH(512)", local_2c != 0x200)) {
        local_38 = "DH(1024)";
      }
    }
    else {
      local_38 = "KRB5";
      if (uVar2 != 0x10) goto LAB_080c7393;
    }
  }
  else if (uVar2 == 0x100) {
    local_38 = "PSK";
  }
  else if (uVar2 < 0x101) {
    local_38 = "ECDH/ECDSA";
    if ((uVar2 != 0x40) && (local_38 = "ECDH", uVar2 != 0x80)) goto LAB_080c7393;
  }
  else {
    local_38 = "GOST";
    if ((uVar2 != 0x200) && (local_38 = "SRP", uVar2 != 0x400)) {
LAB_080c7393:
      local_38 = "unknown";
    }
  }
  if (uVar3 == 0x20) {
    pcVar6 = "KRB5";
  }
  else if (uVar3 < 0x21) {
    if (uVar3 == 4) {
      pcVar6 = "None";
    }
    else if (uVar3 < 5) {
      pcVar6 = "RSA";
      if ((uVar3 != 1) && (pcVar6 = "DSS", uVar3 != 2)) {
LAB_080c74ee:
        pcVar6 = "unknown";
      }
    }
    else {
      pcVar6 = "DH";
      if ((uVar3 != 8) && (pcVar6 = "ECDH", uVar3 != 0x10)) goto LAB_080c74ee;
    }
  }
  else if (uVar3 == 0x100) {
    pcVar6 = "GOST94";
  }
  else if (uVar3 < 0x101) {
    pcVar6 = "ECDSA";
    if ((uVar3 != 0x40) && (pcVar6 = "PSK", uVar3 != 0x80)) goto LAB_080c74ee;
  }
  else {
    pcVar6 = "GOST01";
    if ((uVar3 != 0x200) && (pcVar6 = "SRP", uVar3 != 0x400)) goto LAB_080c74ee;
  }
  if (uVar4 == 0x40) {
    pcVar11 = "AES(128)";
    goto LAB_080c7320;
  }
  if (uVar4 < 0x41) {
    if (uVar4 == 4) {
      if (uVar10 == 0) {
        pcVar11 = "RC4(128)";
        if ((param_1->algorithm2 & 2) != 0) {
          pcVar11 = "RC4(64)";
        }
      }
      else {
        pcVar11 = "RC4(56)";
        if (cVar5 == '\x05') {
          pcVar11 = "RC4(40)";
        }
      }
      goto LAB_080c7320;
    }
    if (uVar4 < 5) {
      if (uVar4 == 1) {
        if ((uVar10 == 0) || (pcVar11 = "DES(40)", bVar12)) {
          pcVar11 = "DES(56)";
        }
        goto LAB_080c7320;
      }
      pcVar11 = "3DES(168)";
      if (uVar4 == 2) goto LAB_080c7320;
    }
    else {
      pcVar11 = "IDEA(128)";
      if ((uVar4 == 0x10) || (pcVar11 = "None", uVar4 == 0x20)) goto LAB_080c7320;
      if (uVar4 == 8) {
        pcVar11 = "RC2(128)";
        if ((uVar10 != 0) && (pcVar11 = "RC2(56)", cVar5 == '\x05')) {
          pcVar11 = "RC2(40)";
        }
        goto LAB_080c7320;
      }
    }
  }
  else {
    if (uVar4 == 0x400) {
      pcVar11 = "GOST89(256)";
      goto LAB_080c7320;
    }
    if (uVar4 < 0x401) {
      pcVar11 = "Camellia(128)";
      if (((uVar4 == 0x100) || (pcVar11 = "Camellia(256)", uVar4 == 0x200)) ||
         (pcVar11 = "AES(256)", uVar4 == 0x80)) goto LAB_080c7320;
    }
    else {
      pcVar11 = "AESGCM(128)";
      if (((uVar4 == 0x1000) || (pcVar11 = "AESGCM(256)", uVar4 == 0x2000)) ||
         (pcVar11 = "SEED(128)", uVar4 == 0x800)) goto LAB_080c7320;
    }
  }
  pcVar11 = "unknown";
LAB_080c7320:
  switch(param_1->algorithm_mac) {
  default:
    pcVar7 = "unknown";
    break;
  case 1:
    pcVar7 = "MD5";
    break;
  case 2:
    pcVar7 = "SHA1";
    break;
  case 4:
    pcVar7 = "GOST94";
    break;
  case 8:
    pcVar7 = "GOST89";
    break;
  case 0x10:
    pcVar7 = "SHA256";
    break;
  case 0x20:
    pcVar7 = "SHA384";
    break;
  case 0x40:
    pcVar7 = "AEAD";
  }
  if (buf == (char *)0x0) {
    buf = (char *)CRYPTO_malloc(0x80,"ssl_ciph.c",0x6e5);
    if (buf == (char *)0x0) {
      return "OPENSSL_malloc Error";
    }
    size = 0x80;
  }
  else if (size < 0x80) {
    return "Buffer too small";
  }
  BIO_snprintf(buf,size,"%-23s %s Kx=%-8s Au=%-4s Enc=%-9s Mac=%-4s%s\n",param_1->name,pcVar9,
               local_38,pcVar6,pcVar11,pcVar7,pcVar8);
  return buf;
}

