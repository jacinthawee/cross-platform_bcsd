
char * SSL_CIPHER_description(SSL_CIPHER *param_1,char *buf,int size)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  char *pcVar9;
  char *pcVar10;
  char *pcVar11;
  char *pcVar12;
  char *pcVar13;
  char *pcVar14;
  
  uVar1 = param_1->algorithm_mkey;
  uVar6 = param_1->algo_strength & 2;
  uVar3 = param_1->algorithm_auth;
  uVar2 = param_1->algorithm_enc;
  uVar7 = param_1->algorithm_mac;
  uVar5 = param_1->algorithm_ssl;
  if ((param_1->algo_strength & 8) == 0) {
    iVar4 = 7;
    iVar8 = 0x400;
    if (uVar2 == 1) {
      iVar4 = 8;
    }
    if (uVar6 == 0) goto LAB_004b5338;
LAB_004b52f8:
    pcVar11 = " export";
    if ((uVar5 & 1) == 0) goto LAB_004b5308;
LAB_004b5348:
    pcVar10 = "SSLv2";
  }
  else {
    iVar8 = 0x200;
    iVar4 = 5;
    if (uVar6 != 0) goto LAB_004b52f8;
LAB_004b5338:
    pcVar11 = "";
    if ((uVar5 & 1) != 0) goto LAB_004b5348;
LAB_004b5308:
    if ((uVar5 & 2) == 0) {
      if ((uVar5 & 4) == 0) {
        pcVar10 = "unknown";
      }
      else {
        pcVar10 = "TLSv1.2";
      }
    }
    else {
      pcVar10 = "SSLv3";
    }
  }
  if (uVar1 == 0x10) {
    pcVar14 = "KRB5";
  }
  else if (uVar1 < 0x11) {
    if (uVar1 == 2) {
      pcVar14 = "DH/RSA";
    }
    else if (uVar1 < 3) {
      if (uVar1 == 1) {
        if (uVar6 == 0) {
          pcVar14 = "RSA";
        }
        else if (iVar8 == 0x200) {
          pcVar14 = "RSA(512)";
        }
        else {
          pcVar14 = "RSA(1024)";
        }
      }
      else {
LAB_004b573c:
        pcVar14 = "unknown";
      }
    }
    else if (uVar1 == 4) {
      pcVar14 = "DH/DSS";
    }
    else {
      if (uVar1 != 8) goto LAB_004b573c;
      if (uVar6 == 0) {
        pcVar14 = "DH";
      }
      else if (iVar8 == 0x200) {
        pcVar14 = "DH(512)";
      }
      else {
        pcVar14 = "DH(1024)";
      }
    }
  }
  else if (uVar1 == 0x80) {
    pcVar14 = "ECDH";
  }
  else if (uVar1 < 0x81) {
    if (uVar1 == 0x20) {
      pcVar14 = "ECDH/RSA";
    }
    else {
      if (uVar1 != 0x40) goto LAB_004b573c;
      pcVar14 = "ECDH/ECDSA";
    }
  }
  else if (uVar1 == 0x100) {
    pcVar14 = "PSK";
  }
  else {
    if (uVar1 != 0x400) goto LAB_004b573c;
    pcVar14 = "SRP";
  }
  if (uVar3 == 8) {
    pcVar12 = "DH";
  }
  else if (uVar3 < 9) {
    if (uVar3 == 2) {
      pcVar12 = "DSS";
    }
    else if (uVar3 == 4) {
      pcVar12 = "None";
    }
    else {
      if (uVar3 != 1) goto LAB_004b55e4;
      pcVar12 = "RSA";
    }
  }
  else if (uVar3 == 0x20) {
    pcVar12 = "KRB5";
  }
  else if (uVar3 < 0x21) {
    if (uVar3 == 0x10) {
      pcVar12 = "ECDH";
    }
    else {
LAB_004b55e4:
      pcVar12 = "unknown";
    }
  }
  else if (uVar3 == 0x40) {
    pcVar12 = "ECDSA";
  }
  else {
    if (uVar3 != 0x80) goto LAB_004b55e4;
    pcVar12 = "PSK";
  }
  if (uVar2 == 0x40) {
    pcVar13 = "AES(128)";
  }
  else if (uVar2 < 0x41) {
    if (uVar2 == 4) {
      if (uVar6 == 0) {
        if ((param_1->algorithm2 & 2) == 0) {
          pcVar13 = "RC4(128)";
        }
        else {
          pcVar13 = "RC4(64)";
        }
      }
      else if (iVar4 == 5) {
        pcVar13 = "RC4(40)";
      }
      else {
        pcVar13 = "RC4(56)";
      }
    }
    else if (uVar2 < 5) {
      if (uVar2 == 1) {
        if ((uVar6 == 0) || (iVar4 != 5)) {
          pcVar13 = "DES(56)";
        }
        else {
          pcVar13 = "DES(40)";
        }
      }
      else if (uVar2 == 2) {
        pcVar13 = "3DES(168)";
      }
      else {
LAB_004b540c:
        pcVar13 = "unknown";
      }
    }
    else if (uVar2 == 0x10) {
      pcVar13 = "IDEA(128)";
    }
    else if (uVar2 == 0x20) {
      pcVar13 = "None";
    }
    else {
      if (uVar2 != 8) goto LAB_004b540c;
      if (uVar6 == 0) {
        pcVar13 = "RC2(128)";
      }
      else if (iVar4 == 5) {
        pcVar13 = "RC2(40)";
      }
      else {
        pcVar13 = "RC2(56)";
      }
    }
  }
  else if (uVar2 == 0x200) {
    pcVar13 = "Camellia(256)";
  }
  else if (uVar2 < 0x201) {
    if (uVar2 == 0x80) {
      pcVar13 = "AES(256)";
    }
    else {
      if (uVar2 != 0x100) goto LAB_004b540c;
      pcVar13 = "Camellia(128)";
    }
  }
  else if (uVar2 == 0x1000) {
    pcVar13 = "AESGCM(128)";
  }
  else if (uVar2 == 0x2000) {
    pcVar13 = "AESGCM(256)";
  }
  else {
    if (uVar2 != 0x800) goto LAB_004b540c;
    pcVar13 = "SEED(128)";
  }
  if (uVar7 == 0x10) {
    pcVar9 = "SHA256";
    goto LAB_004b5440;
  }
  if (uVar7 < 0x11) {
    if (uVar7 == 1) {
      pcVar9 = "MD5";
      goto LAB_004b5440;
    }
    if (uVar7 == 2) {
      pcVar9 = "SHA1";
      goto LAB_004b5440;
    }
  }
  else {
    if (uVar7 == 0x20) {
      pcVar9 = "SHA384";
      goto LAB_004b5440;
    }
    if (uVar7 == 0x40) {
      pcVar9 = "AEAD";
      goto LAB_004b5440;
    }
  }
  pcVar9 = "unknown";
LAB_004b5440:
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
  (*(code *)PTR_BIO_snprintf_006a8060)
            (buf,size,"%-23s %s Kx=%-8s Au=%-4s Enc=%-9s Mac=%-4s%s\n",param_1->name,pcVar10,pcVar14
             ,pcVar12,pcVar13,pcVar9,pcVar11);
  return buf;
}

