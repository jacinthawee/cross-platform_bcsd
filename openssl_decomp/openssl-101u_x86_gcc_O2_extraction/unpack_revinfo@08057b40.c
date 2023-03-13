
undefined4
unpack_revinfo(ASN1_UTCTIME **param_1,int *param_2,ASN1_OBJECT **param_3,
              ASN1_GENERALIZEDTIME **param_4,char *param_5)

{
  char *__s;
  char *pcVar1;
  char *pcVar2;
  ASN1_UTCTIME *s;
  int iVar3;
  ASN1_GENERALIZEDTIME *s_00;
  char *__s_00;
  ASN1_OBJECT *a;
  undefined4 uVar4;
  int local_20;
  
  __s = BUF_strdup(param_5);
  if (__s == (char *)0x0) {
    s_00 = (ASN1_GENERALIZEDTIME *)0x0;
    a = (ASN1_OBJECT *)0x0;
    uVar4 = 0;
    BIO_printf(bio_err,"memory allocation failure\n");
    goto LAB_08057d06;
  }
  pcVar1 = strchr(__s,0x2c);
  if (pcVar1 == (char *)0x0) {
    if (param_1 != (ASN1_UTCTIME **)0x0) {
      pcVar1 = (char *)0x0;
      __s_00 = (char *)0x0;
      goto LAB_08057b9d;
    }
LAB_08057d40:
    s_00 = (ASN1_GENERALIZEDTIME *)0x0;
    a = (ASN1_OBJECT *)0x0;
    iVar3 = -1;
    goto LAB_08057d49;
  }
  __s_00 = pcVar1 + 1;
  *pcVar1 = '\0';
  pcVar2 = strchr(__s_00,0x2c);
  if (pcVar2 == (char *)0x0) {
    pcVar1 = (char *)0x0;
  }
  else {
    pcVar1 = pcVar2 + 1;
    *pcVar2 = '\0';
  }
  if (param_1 != (ASN1_UTCTIME **)0x0) {
LAB_08057b9d:
    s = ASN1_UTCTIME_new();
    *param_1 = s;
    if (s == (ASN1_UTCTIME *)0x0) {
      pcVar1 = "memory allocation failure\n";
    }
    else {
      iVar3 = ASN1_UTCTIME_set_string(s,__s);
      if (iVar3 != 0) {
        if (__s_00 == (char *)0x0) goto LAB_08057d40;
        goto LAB_08057bca;
      }
      pcVar1 = "invalid revocation date %s\n";
    }
    goto LAB_08057ce6;
  }
LAB_08057bca:
  iVar3 = strcasecmp(__s_00,"unspecified");
  if (iVar3 == 0) {
    iVar3 = 0;
LAB_08057e38:
    s_00 = (ASN1_GENERALIZEDTIME *)0x0;
    a = (ASN1_OBJECT *)0x0;
LAB_08057d49:
    if (param_2 != (int *)0x0) {
      *param_2 = iVar3;
    }
    if (param_4 == (ASN1_GENERALIZEDTIME **)0x0) {
      uVar4 = 1;
      ASN1_GENERALIZEDTIME_free(s_00);
    }
    else {
      uVar4 = 1;
      *param_4 = s_00;
    }
  }
  else {
    iVar3 = strcasecmp(__s_00,"keyCompromise");
    if (iVar3 == 0) {
      iVar3 = 1;
      goto LAB_08057e38;
    }
    iVar3 = strcasecmp(__s_00,"CACompromise");
    if (iVar3 == 0) {
      iVar3 = 2;
      goto LAB_08057e38;
    }
    iVar3 = strcasecmp(__s_00,"affiliationChanged");
    if (iVar3 == 0) {
      iVar3 = 3;
      goto LAB_08057e38;
    }
    iVar3 = strcasecmp(__s_00,"superseded");
    if (iVar3 == 0) {
      iVar3 = 4;
      goto LAB_08057e38;
    }
    iVar3 = strcasecmp(__s_00,"cessationOfOperation");
    if (iVar3 == 0) {
      iVar3 = 5;
      goto LAB_08057e38;
    }
    iVar3 = strcasecmp(__s_00,"certificateHold");
    if (iVar3 == 0) {
      iVar3 = 6;
      goto LAB_08057e38;
    }
    iVar3 = strcasecmp(__s_00,"removeFromCRL");
    if (iVar3 == 0) {
      s_00 = (ASN1_GENERALIZEDTIME *)0x0;
      a = (ASN1_OBJECT *)0x0;
      iVar3 = 8;
      goto LAB_08057d49;
    }
    iVar3 = strcasecmp(__s_00,"holdInstruction");
    if (iVar3 == 0) {
      if (pcVar1 == (char *)0x0) {
        pcVar1 = "missing hold instruction\n";
        goto LAB_08057ce6;
      }
      a = OBJ_txt2obj(pcVar1,0);
      if (a != (ASN1_OBJECT *)0x0) {
        if (param_3 == (ASN1_OBJECT **)0x0) {
          s_00 = (ASN1_GENERALIZEDTIME *)0x0;
          iVar3 = 6;
        }
        else {
          s_00 = (ASN1_GENERALIZEDTIME *)0x0;
          *param_3 = a;
          iVar3 = 6;
        }
        goto LAB_08057d49;
      }
      s_00 = (ASN1_GENERALIZEDTIME *)0x0;
      uVar4 = 0;
      BIO_printf(bio_err,"invalid object identifier %s\n",pcVar1);
    }
    else {
      iVar3 = strcasecmp(__s_00,"keyTime");
      if (iVar3 == 0) {
        local_20 = 9;
      }
      else {
        iVar3 = strcasecmp(__s_00,"CAkeyTime");
        if (iVar3 != 0) {
          pcVar1 = "invalid reason code %s\n";
          goto LAB_08057ce6;
        }
        local_20 = 10;
      }
      if (pcVar1 == (char *)0x0) {
        pcVar1 = "missing compromised time\n";
LAB_08057ce6:
        s_00 = (ASN1_GENERALIZEDTIME *)0x0;
        a = (ASN1_OBJECT *)0x0;
        uVar4 = 0;
        BIO_printf(bio_err,pcVar1);
      }
      else {
        s_00 = ASN1_GENERALIZEDTIME_new();
        if (s_00 == (ASN1_GENERALIZEDTIME *)0x0) {
          pcVar1 = "memory allocation failure\n";
        }
        else {
          iVar3 = ASN1_GENERALIZEDTIME_set_string(s_00,pcVar1);
          if (iVar3 != 0) {
            a = (ASN1_OBJECT *)0x0;
            iVar3 = (local_20 != 9) + 1;
            goto LAB_08057d49;
          }
          pcVar1 = "invalid compromised time %s\n";
        }
        a = (ASN1_OBJECT *)0x0;
        uVar4 = 0;
        BIO_printf(bio_err,pcVar1);
      }
    }
  }
  CRYPTO_free(__s);
LAB_08057d06:
  if (param_3 == (ASN1_OBJECT **)0x0) {
    ASN1_OBJECT_free(a);
  }
  if (param_4 != (ASN1_GENERALIZEDTIME **)0x0) {
    return uVar4;
  }
  ASN1_GENERALIZEDTIME_free(s_00);
  return uVar4;
}

