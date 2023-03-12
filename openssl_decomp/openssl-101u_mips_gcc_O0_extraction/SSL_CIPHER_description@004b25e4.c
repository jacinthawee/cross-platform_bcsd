
char * SSL_CIPHER_description(SSL_CIPHER *param_1,char *buf,int size)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  char *pcVar9;
  char *pcVar10;
  char *pcVar11;
  char *pcVar12;
  char *pcVar13;
  
  uVar1 = param_1->algorithm_mkey;
  uVar2 = param_1->algorithm_enc;
  uVar3 = param_1->algorithm_auth;
  uVar5 = param_1->algo_strength & 2;
  uVar4 = param_1->algorithm_ssl;
  if ((param_1->algo_strength & 8) == 0) {
    iVar6 = 7;
    iVar7 = 0x400;
    if (uVar2 == 1) {
      iVar6 = 8;
    }
    if (uVar5 != 0) goto LAB_004b2654;
LAB_004b2694:
    pcVar10 = "";
    if ((uVar4 & 1) == 0) goto LAB_004b2664;
LAB_004b26a4:
    pcVar9 = "SSLv2";
  }
  else {
    iVar7 = 0x200;
    iVar6 = 5;
    if (uVar5 == 0) goto LAB_004b2694;
LAB_004b2654:
    pcVar10 = " export";
    if ((uVar4 & 1) != 0) goto LAB_004b26a4;
LAB_004b2664:
    if ((uVar4 & 2) == 0) {
      if ((uVar4 & 4) == 0) {
        pcVar9 = "unknown";
      }
      else {
        pcVar9 = "TLSv1.2";
      }
    }
    else {
      pcVar9 = "SSLv3";
    }
  }
  if (uVar1 == 0x20) {
    pcVar11 = "ECDH/RSA";
  }
  else if (uVar1 < 0x21) {
    if (uVar1 == 4) {
      pcVar11 = "DH/DSS";
    }
    else if (uVar1 < 5) {
      if (uVar1 == 1) {
        if (uVar5 == 0) {
          pcVar11 = "RSA";
        }
        else if (iVar7 == 0x200) {
          pcVar11 = "RSA(512)";
        }
        else {
          pcVar11 = "RSA(1024)";
        }
      }
      else if (uVar1 == 2) {
        pcVar11 = "DH/RSA";
      }
      else {
LAB_004b2aa4:
        pcVar11 = "unknown";
      }
    }
    else if (uVar1 == 8) {
      if (uVar5 == 0) {
        pcVar11 = "DH";
      }
      else if (iVar7 == 0x200) {
        pcVar11 = "DH(512)";
      }
      else {
        pcVar11 = "DH(1024)";
      }
    }
    else {
      if (uVar1 != 0x10) goto LAB_004b2aa4;
      pcVar11 = "KRB5";
    }
  }
  else if (uVar1 == 0x100) {
    pcVar11 = "PSK";
  }
  else if (uVar1 < 0x101) {
    if (uVar1 == 0x40) {
      pcVar11 = "ECDH/ECDSA";
    }
    else {
      if (uVar1 != 0x80) goto LAB_004b2aa4;
      pcVar11 = "ECDH";
    }
  }
  else if (uVar1 == 0x200) {
    pcVar11 = "GOST";
  }
  else {
    if (uVar1 != 0x400) goto LAB_004b2aa4;
    pcVar11 = "SRP";
  }
  if (uVar3 == 0x20) {
    pcVar12 = "KRB5";
  }
  else if (uVar3 < 0x21) {
    if (uVar3 == 4) {
      pcVar12 = "None";
    }
    else if (uVar3 < 5) {
      if (uVar3 == 1) {
        pcVar12 = "RSA";
      }
      else if (uVar3 == 2) {
        pcVar12 = "DSS";
      }
      else {
LAB_004b2a8c:
        pcVar12 = "unknown";
      }
    }
    else if (uVar3 == 8) {
      pcVar12 = "DH";
    }
    else {
      if (uVar3 != 0x10) goto LAB_004b2a8c;
      pcVar12 = "ECDH";
    }
  }
  else if (uVar3 == 0x100) {
    pcVar12 = "GOST94";
  }
  else if (uVar3 < 0x101) {
    if (uVar3 == 0x40) {
      pcVar12 = "ECDSA";
    }
    else {
      if (uVar3 != 0x80) goto LAB_004b2a8c;
      pcVar12 = "PSK";
    }
  }
  else if (uVar3 == 0x200) {
    pcVar12 = "GOST01";
  }
  else {
    if (uVar3 != 0x400) goto LAB_004b2a8c;
    pcVar12 = "SRP";
  }
  if (uVar2 == 0x40) {
    pcVar13 = "AES(128)";
    goto LAB_004b2770;
  }
  if (uVar2 < 0x41) {
    if (uVar2 == 4) {
      if (uVar5 == 0) {
        if ((param_1->algorithm2 & 2) == 0) {
          pcVar13 = "RC4(128)";
        }
        else {
          pcVar13 = "RC4(64)";
        }
      }
      else if (iVar6 == 5) {
        pcVar13 = "RC4(40)";
      }
      else {
        pcVar13 = "RC4(56)";
      }
      goto LAB_004b2770;
    }
    if (uVar2 < 5) {
      if (uVar2 == 1) {
        if ((uVar5 == 0) || (iVar6 != 5)) {
          pcVar13 = "DES(56)";
        }
        else {
          pcVar13 = "DES(40)";
        }
        goto LAB_004b2770;
      }
      if (uVar2 == 2) {
        pcVar13 = "3DES(168)";
        goto LAB_004b2770;
      }
    }
    else {
      if (uVar2 == 0x10) {
        pcVar13 = "IDEA(128)";
        goto LAB_004b2770;
      }
      if (uVar2 == 0x20) {
        pcVar13 = "None";
        goto LAB_004b2770;
      }
      if (uVar2 == 8) {
        if (uVar5 == 0) {
          pcVar13 = "RC2(128)";
        }
        else if (iVar6 == 5) {
          pcVar13 = "RC2(40)";
        }
        else {
          pcVar13 = "RC2(56)";
        }
        goto LAB_004b2770;
      }
    }
  }
  else {
    if (uVar2 == 0x400) {
      pcVar13 = "GOST89(256)";
      goto LAB_004b2770;
    }
    if (uVar2 < 0x401) {
      if (uVar2 == 0x100) {
        pcVar13 = "Camellia(128)";
        goto LAB_004b2770;
      }
      if (uVar2 == 0x200) {
        pcVar13 = "Camellia(256)";
        goto LAB_004b2770;
      }
      if (uVar2 == 0x80) {
        pcVar13 = "AES(256)";
        goto LAB_004b2770;
      }
    }
    else {
      if (uVar2 == 0x1000) {
        pcVar13 = "AESGCM(128)";
        goto LAB_004b2770;
      }
      if (uVar2 == 0x2000) {
        pcVar13 = "AESGCM(256)";
        goto LAB_004b2770;
      }
      if (uVar2 == 0x800) {
        pcVar13 = "SEED(128)";
        goto LAB_004b2770;
      }
    }
  }
  pcVar13 = "unknown";
LAB_004b2770:
  switch(param_1->algorithm_mac) {
  default:
    pcVar8 = "unknown";
    break;
  case 1:
    pcVar8 = "MD5";
    break;
  case 2:
    pcVar8 = "SHA1";
    break;
  case 4:
    pcVar8 = "GOST94";
    break;
  case 8:
    pcVar8 = "GOST89";
    break;
  case 0x10:
    pcVar8 = "SHA256";
    break;
  case 0x20:
    pcVar8 = "SHA384";
    break;
  case 0x40:
    pcVar8 = "AEAD";
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
  (*(code *)PTR_BIO_snprintf_006a6f60)
            (buf,size,"%-23s %s Kx=%-8s Au=%-4s Enc=%-9s Mac=%-4s%s\n",param_1->name,pcVar9,pcVar11,
             pcVar12,pcVar13,pcVar8,pcVar10);
  return buf;
}

