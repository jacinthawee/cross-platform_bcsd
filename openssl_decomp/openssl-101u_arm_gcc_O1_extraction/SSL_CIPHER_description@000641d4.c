
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
  char *pcVar10;
  int iVar11;
  char *pcVar12;
  uint uVar13;
  int iVar14;
  
  uVar3 = param_1->algorithm_mkey;
  uVar5 = param_1->algorithm_auth;
  uVar1 = param_1->algo_strength & 2;
  uVar2 = param_1->algorithm_enc;
  uVar13 = param_1->algo_strength & 8;
  uVar7 = param_1->algorithm_ssl;
  if (uVar13 == 0) {
    iVar11 = 0x400;
    if (uVar2 == 1) {
      iVar14 = 8;
    }
    else {
      iVar14 = 7;
    }
  }
  else {
    uVar13 = 1;
    iVar11 = 0x200;
    iVar14 = 5;
  }
  pcVar10 = "";
  if (uVar1 != 0) {
    pcVar10 = " export";
  }
  if ((int)(uVar7 << 0x1f) < 0) {
    pcVar9 = "SSLv2";
  }
  else if ((int)(uVar7 << 0x1e) < 0) {
    pcVar9 = "SSLv3";
  }
  else {
    pcVar9 = "unknown";
    if ((uVar7 & 4) != 0) {
      pcVar9 = "TLSv1.2";
    }
  }
  if (uVar3 == 0x20) {
    pcVar8 = "ECDH/RSA";
  }
  else if (uVar3 < 0x21) {
    if (uVar3 == 4) {
      pcVar8 = "DH/DSS";
    }
    else if (uVar3 < 5) {
      if (uVar3 == 1) {
        pcVar8 = "RSA";
        if (uVar1 != 0) {
          pcVar8 = "RSA(1024)";
          if (iVar11 == 0x200) {
            pcVar8 = "RSA(512)";
          }
        }
      }
      else if (uVar3 == 2) {
        pcVar8 = "DH/RSA";
      }
      else {
LAB_0006435c:
        pcVar8 = "unknown";
      }
    }
    else if (uVar3 == 8) {
      pcVar8 = "DH";
      if (uVar1 != 0) {
        pcVar8 = "DH(1024)";
        if (iVar11 == 0x200) {
          pcVar8 = "DH(512)";
        }
      }
    }
    else {
      if (uVar3 != 0x10) goto LAB_0006435c;
      pcVar8 = "KRB5";
    }
  }
  else if (uVar3 == 0x100) {
    pcVar8 = "PSK";
  }
  else if (uVar3 < 0x101) {
    if (uVar3 == 0x40) {
      pcVar8 = "ECDH/ECDSA";
    }
    else {
      if (uVar3 != 0x80) goto LAB_0006435c;
      pcVar8 = "ECDH";
    }
  }
  else if (uVar3 == 0x200) {
    pcVar8 = "GOST";
  }
  else {
    if (uVar3 != 0x400) goto LAB_0006435c;
    pcVar8 = "SRP";
  }
  if (uVar5 == 0x20) {
    pcVar4 = "KRB5";
  }
  else if (uVar5 < 0x21) {
    if (uVar5 == 4) {
      pcVar4 = "None";
    }
    else if (uVar5 < 5) {
      if (uVar5 == 1) {
        pcVar4 = "RSA";
      }
      else if (uVar5 == 2) {
        pcVar4 = "DSS";
      }
      else {
LAB_0006447e:
        pcVar4 = "unknown";
      }
    }
    else if (uVar5 == 8) {
      pcVar4 = "DH";
    }
    else {
      if (uVar5 != 0x10) goto LAB_0006447e;
      pcVar4 = "ECDH";
    }
  }
  else if (uVar5 == 0x100) {
    pcVar4 = "GOST94";
  }
  else if (uVar5 < 0x101) {
    if (uVar5 == 0x40) {
      pcVar4 = "ECDSA";
    }
    else {
      if (uVar5 != 0x80) goto LAB_0006447e;
      pcVar4 = "PSK";
    }
  }
  else if (uVar5 == 0x200) {
    pcVar4 = "GOST01";
  }
  else {
    if (uVar5 != 0x400) goto LAB_0006447e;
    pcVar4 = "SRP";
  }
  if (uVar2 == 0x40) {
    pcVar6 = "AES(128)";
    goto LAB_000642d2;
  }
  if (uVar2 < 0x41) {
    if (uVar2 == 4) {
      if (uVar1 == 0) {
        pcVar6 = "RC4(128)";
        if ((param_1->algorithm2 & 2) != 0) {
          pcVar6 = "RC4(64)";
        }
      }
      else {
        pcVar6 = "RC4(56)";
        if (iVar14 == 5) {
          pcVar6 = "RC4(40)";
        }
      }
      goto LAB_000642d2;
    }
    if (uVar2 < 5) {
      if (uVar2 == 1) {
        if (uVar1 == 0) {
          uVar13 = 0;
        }
        else {
          uVar13 = uVar13 & 1;
        }
        pcVar6 = "DES(56)";
        if (uVar13 != 0) {
          pcVar6 = "DES(40)";
        }
        goto LAB_000642d2;
      }
      if (uVar2 == 2) {
        pcVar6 = "3DES(168)";
        goto LAB_000642d2;
      }
    }
    else {
      if (uVar2 == 0x10) {
        pcVar6 = "IDEA(128)";
        goto LAB_000642d2;
      }
      if (uVar2 == 0x20) {
        pcVar6 = "None";
        goto LAB_000642d2;
      }
      if (uVar2 == 8) {
        pcVar6 = "RC2(128)";
        if (uVar1 != 0) {
          pcVar6 = "RC2(56)";
          if (iVar14 == 5) {
            pcVar6 = "RC2(40)";
          }
        }
        goto LAB_000642d2;
      }
    }
  }
  else {
    if (uVar2 == 0x400) {
      pcVar6 = "GOST89(256)";
      goto LAB_000642d2;
    }
    if (uVar2 < 0x401) {
      if (uVar2 == 0x100) {
        pcVar6 = "Camellia(128)";
        goto LAB_000642d2;
      }
      if (uVar2 == 0x200) {
        pcVar6 = "Camellia(256)";
        goto LAB_000642d2;
      }
      if (uVar2 == 0x80) {
        pcVar6 = "AES(256)";
        goto LAB_000642d2;
      }
    }
    else {
      if (uVar2 == 0x1000) {
        pcVar6 = "AESGCM(128)";
        goto LAB_000642d2;
      }
      if (uVar2 == 0x2000) {
        pcVar6 = "AESGCM(256)";
        goto LAB_000642d2;
      }
      if (uVar2 == 0x800) {
        pcVar6 = "SEED(128)";
        goto LAB_000642d2;
      }
    }
  }
  pcVar6 = "unknown";
LAB_000642d2:
  switch(param_1->algorithm_mac) {
  case 1:
    pcVar12 = "MD5";
    break;
  case 2:
    pcVar12 = "SHA1";
    break;
  default:
    pcVar12 = "unknown";
    break;
  case 4:
    pcVar12 = "GOST94";
    break;
  case 8:
    pcVar12 = "GOST89";
    break;
  case 0x10:
    pcVar12 = "SHA256";
    break;
  case 0x20:
    pcVar12 = "SHA384";
    break;
  case 0x40:
    pcVar12 = "AEAD";
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
  BIO_snprintf(buf,size,"%-23s %s Kx=%-8s Au=%-4s Enc=%-9s Mac=%-4s%s\n",param_1->name,pcVar9,pcVar8
               ,pcVar4,pcVar6,pcVar12,pcVar10);
  return buf;
}

