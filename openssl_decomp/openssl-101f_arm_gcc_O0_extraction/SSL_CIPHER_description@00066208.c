
char * SSL_CIPHER_description(SSL_CIPHER *param_1,char *buf,int size)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  uint uVar5;
  char *pcVar6;
  uint uVar7;
  char *pcVar8;
  char *pcVar9;
  uint uVar10;
  char *pcVar11;
  int iVar12;
  char *pcVar13;
  int iVar14;
  uint uVar15;
  
  uVar2 = param_1->algo_strength & 2;
  uVar15 = param_1->algo_strength & 8;
  uVar5 = param_1->algorithm_mkey;
  uVar10 = param_1->algorithm_auth;
  uVar3 = param_1->algorithm_enc;
  uVar7 = param_1->algorithm_ssl;
  uVar1 = param_1->algorithm_mac;
  if (uVar15 == 0) {
    iVar12 = 0x400;
    if (uVar3 == 1) {
      iVar14 = 8;
    }
    else {
      iVar14 = 7;
    }
  }
  else {
    uVar15 = 1;
    iVar12 = 0x200;
    iVar14 = 5;
  }
  pcVar9 = "";
  if (uVar2 != 0) {
    pcVar9 = " export";
  }
  if ((int)(uVar7 << 0x1f) < 0) {
    pcVar4 = "SSLv2";
  }
  else if ((int)(uVar7 << 0x1e) < 0) {
    pcVar4 = "SSLv3";
  }
  else {
    pcVar4 = "TLSv1.2";
    if ((uVar7 & 4) == 0) {
      pcVar4 = "unknown";
    }
  }
  if (uVar5 == 0x10) {
    pcVar8 = "KRB5";
  }
  else if (uVar5 < 0x11) {
    if (uVar5 == 2) {
      pcVar8 = "DH/RSA";
    }
    else if (uVar5 < 3) {
      if (uVar5 == 1) {
        pcVar8 = "RSA";
        if (uVar2 != 0) {
          pcVar8 = "RSA(1024)";
          if (iVar12 == 0x200) {
            pcVar8 = "RSA(512)";
          }
        }
      }
      else {
LAB_000663fc:
        pcVar8 = "unknown";
      }
    }
    else if (uVar5 == 4) {
      pcVar8 = "DH/DSS";
    }
    else {
      if (uVar5 != 8) goto LAB_000663fc;
      pcVar8 = "DH";
      if (uVar2 != 0) {
        pcVar8 = "DH(1024)";
        if (iVar12 == 0x200) {
          pcVar8 = "DH(512)";
        }
      }
    }
  }
  else if (uVar5 == 0x80) {
    pcVar8 = "ECDH";
  }
  else if (uVar5 < 0x81) {
    if (uVar5 == 0x20) {
      pcVar8 = "ECDH/RSA";
    }
    else {
      if (uVar5 != 0x40) goto LAB_000663fc;
      pcVar8 = "ECDH/ECDSA";
    }
  }
  else if (uVar5 == 0x100) {
    pcVar8 = "PSK";
  }
  else {
    if (uVar5 != 0x400) goto LAB_000663fc;
    pcVar8 = "SRP";
  }
  if (uVar10 == 8) {
    pcVar6 = "DH";
  }
  else if (uVar10 < 9) {
    if (uVar10 == 2) {
      pcVar6 = "DSS";
    }
    else if (uVar10 == 4) {
      pcVar6 = "None";
    }
    else {
      if (uVar10 != 1) goto LAB_000663ce;
      pcVar6 = "RSA";
    }
  }
  else if (uVar10 == 0x20) {
    pcVar6 = "KRB5";
  }
  else if (uVar10 < 0x21) {
    if (uVar10 == 0x10) {
      pcVar6 = "ECDH";
    }
    else {
LAB_000663ce:
      pcVar6 = "unknown";
    }
  }
  else if (uVar10 == 0x40) {
    pcVar6 = "ECDSA";
  }
  else {
    if (uVar10 != 0x80) goto LAB_000663ce;
    pcVar6 = "PSK";
  }
  if (uVar3 == 0x40) {
    pcVar11 = "AES(128)";
  }
  else if (uVar3 < 0x41) {
    if (uVar3 == 4) {
      if (uVar2 == 0) {
        pcVar11 = "RC4(128)";
        if ((param_1->algorithm2 & 2) != 0) {
          pcVar11 = "RC4(64)";
        }
      }
      else {
        pcVar11 = "RC4(56)";
        if (iVar14 == 5) {
          pcVar11 = "RC4(40)";
        }
      }
    }
    else if (uVar3 < 5) {
      if (uVar3 == 1) {
        if (uVar2 == 0) {
          uVar15 = 0;
        }
        else {
          uVar15 = uVar15 & 1;
        }
        pcVar11 = "DES(56)";
        if (uVar15 != 0) {
          pcVar11 = "DES(40)";
        }
      }
      else if (uVar3 == 2) {
        pcVar11 = "3DES(168)";
      }
      else {
LAB_00066304:
        pcVar11 = "unknown";
      }
    }
    else if (uVar3 == 0x10) {
      pcVar11 = "IDEA(128)";
    }
    else if (uVar3 == 0x20) {
      pcVar11 = "None";
    }
    else {
      if (uVar3 != 8) goto LAB_00066304;
      pcVar11 = "RC2(128)";
      if (uVar2 != 0) {
        pcVar11 = "RC2(56)";
        if (iVar14 == 5) {
          pcVar11 = "RC2(40)";
        }
      }
    }
  }
  else if (uVar3 == 0x200) {
    pcVar11 = "Camellia(256)";
  }
  else if (uVar3 < 0x201) {
    if (uVar3 == 0x80) {
      pcVar11 = "AES(256)";
    }
    else {
      if (uVar3 != 0x100) goto LAB_00066304;
      pcVar11 = "Camellia(128)";
    }
  }
  else if (uVar3 == 0x1000) {
    pcVar11 = "AESGCM(128)";
  }
  else if (uVar3 == 0x2000) {
    pcVar11 = "AESGCM(256)";
  }
  else {
    if (uVar3 != 0x800) goto LAB_00066304;
    pcVar11 = "SEED(128)";
  }
  if (uVar1 == 0x10) {
    pcVar13 = "SHA256";
    goto LAB_00066430;
  }
  if (uVar1 < 0x11) {
    if (uVar1 == 1) {
      pcVar13 = "MD5";
      goto LAB_00066430;
    }
    if (uVar1 == 2) {
      pcVar13 = "SHA1";
      goto LAB_00066430;
    }
  }
  else {
    if (uVar1 == 0x20) {
      pcVar13 = "SHA384";
      goto LAB_00066430;
    }
    if (uVar1 == 0x40) {
      pcVar13 = "AEAD";
      goto LAB_00066430;
    }
  }
  pcVar13 = "unknown";
LAB_00066430:
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
  BIO_snprintf(buf,size,"%-23s %s Kx=%-8s Au=%-4s Enc=%-9s Mac=%-4s%s\n",param_1->name,pcVar4,pcVar8
               ,pcVar6,pcVar11,pcVar13,pcVar9);
  return buf;
}

