
undefined4
unpack_revinfo(ASN1_UTCTIME **param_1,int *param_2,ASN1_OBJECT **param_3,
              ASN1_GENERALIZEDTIME **param_4,char *param_5)

{
  char *__s;
  char *__s_00;
  char *pcVar1;
  ASN1_UTCTIME *pAVar2;
  int iVar3;
  undefined4 uVar4;
  ASN1_GENERALIZEDTIME *s;
  ASN1_OBJECT *a;
  char *s_00;
  int local_20;
  
  __s_00 = BUF_strdup(param_5);
  pcVar1 = strchr(__s_00,0x2c);
  if (pcVar1 == (char *)0x0) {
    if (param_1 != (ASN1_UTCTIME **)0x0) {
      pAVar2 = ASN1_UTCTIME_new();
      *param_1 = pAVar2;
      iVar3 = ASN1_UTCTIME_set_string(pAVar2,__s_00);
      if (iVar3 == 0) goto LAB_08057b50;
    }
    s = (ASN1_GENERALIZEDTIME *)0x0;
    a = (ASN1_OBJECT *)0x0;
    iVar3 = -1;
    goto LAB_08057b7d;
  }
  __s = pcVar1 + 1;
  *pcVar1 = '\0';
  pcVar1 = strchr(__s,0x2c);
  if (pcVar1 == (char *)0x0) {
    s_00 = (char *)0x0;
  }
  else {
    s_00 = pcVar1 + 1;
    *pcVar1 = '\0';
  }
  if (param_1 != (ASN1_UTCTIME **)0x0) {
    pAVar2 = ASN1_UTCTIME_new();
    *param_1 = pAVar2;
    iVar3 = ASN1_UTCTIME_set_string(pAVar2,__s_00);
    if (iVar3 != 0) goto LAB_080579ce;
LAB_08057b50:
    s = (ASN1_GENERALIZEDTIME *)0x0;
    BIO_printf(bio_err,"invalid revocation date %s\n",__s_00);
    goto LAB_08057afa;
  }
LAB_080579ce:
  iVar3 = strcasecmp(__s,"unspecified");
  if (iVar3 == 0) {
    iVar3 = 0;
LAB_08057c70:
    s = (ASN1_GENERALIZEDTIME *)0x0;
    a = (ASN1_OBJECT *)0x0;
LAB_08057b7d:
    if (param_2 != (int *)0x0) {
      *param_2 = iVar3;
    }
    if (param_4 == (ASN1_GENERALIZEDTIME **)0x0) {
      ASN1_GENERALIZEDTIME_free(s);
      CRYPTO_free(__s_00);
      uVar4 = 1;
      if (param_3 != (ASN1_OBJECT **)0x0) goto LAB_08057c45;
    }
    else {
      *param_4 = s;
      CRYPTO_free(__s_00);
      uVar4 = 1;
      if (param_3 != (ASN1_OBJECT **)0x0) {
        return 1;
      }
    }
LAB_08057bba:
    ASN1_OBJECT_free(a);
  }
  else {
    iVar3 = strcasecmp(__s,"keyCompromise");
    if (iVar3 == 0) {
      iVar3 = 1;
      goto LAB_08057c70;
    }
    iVar3 = strcasecmp(__s,"CACompromise");
    if (iVar3 == 0) {
      iVar3 = 2;
      goto LAB_08057c70;
    }
    iVar3 = strcasecmp(__s,"affiliationChanged");
    if (iVar3 == 0) {
      iVar3 = 3;
      goto LAB_08057c70;
    }
    iVar3 = strcasecmp(__s,"superseded");
    if (iVar3 == 0) {
      iVar3 = 4;
      goto LAB_08057c70;
    }
    iVar3 = strcasecmp(__s,"cessationOfOperation");
    if (iVar3 == 0) {
      iVar3 = 5;
      goto LAB_08057c70;
    }
    iVar3 = strcasecmp(__s,"certificateHold");
    if (iVar3 == 0) {
      iVar3 = 6;
      goto LAB_08057c70;
    }
    iVar3 = strcasecmp(__s,"removeFromCRL");
    if (iVar3 == 0) {
      s = (ASN1_GENERALIZEDTIME *)0x0;
      a = (ASN1_OBJECT *)0x0;
      iVar3 = 8;
      goto LAB_08057b7d;
    }
    iVar3 = strcasecmp(__s,"holdInstruction");
    if (iVar3 == 0) {
      if (s_00 == (char *)0x0) {
        s = (ASN1_GENERALIZEDTIME *)0x0;
        BIO_printf(bio_err,"missing hold instruction\n");
      }
      else {
        a = OBJ_txt2obj(s_00,0);
        if (a != (ASN1_OBJECT *)0x0) {
          if (param_3 == (ASN1_OBJECT **)0x0) {
            s = (ASN1_GENERALIZEDTIME *)0x0;
            iVar3 = 6;
          }
          else {
            s = (ASN1_GENERALIZEDTIME *)0x0;
            *param_3 = a;
            iVar3 = 6;
          }
          goto LAB_08057b7d;
        }
        s = (ASN1_GENERALIZEDTIME *)0x0;
        BIO_printf(bio_err,"invalid object identifier %s\n",s_00);
      }
    }
    else {
      iVar3 = strcasecmp(__s,"keyTime");
      if (iVar3 == 0) {
        local_20 = 9;
      }
      else {
        iVar3 = strcasecmp(__s,"CAkeyTime");
        if (iVar3 != 0) {
          s = (ASN1_GENERALIZEDTIME *)0x0;
          BIO_printf(bio_err,"invalid reason code %s\n",__s);
          goto LAB_08057afa;
        }
        local_20 = 10;
      }
      if (s_00 == (char *)0x0) {
        s = (ASN1_GENERALIZEDTIME *)0x0;
        BIO_printf(bio_err,"missing compromised time\n");
      }
      else {
        s = ASN1_GENERALIZEDTIME_new();
        iVar3 = ASN1_GENERALIZEDTIME_set_string(s,s_00);
        if (iVar3 != 0) {
          a = (ASN1_OBJECT *)0x0;
          iVar3 = (local_20 != 9) + 1;
          goto LAB_08057b7d;
        }
        BIO_printf(bio_err,"invalid compromised time %s\n",s_00);
      }
    }
LAB_08057afa:
    CRYPTO_free(__s_00);
    uVar4 = 0;
    if (param_3 == (ASN1_OBJECT **)0x0) {
      a = (ASN1_OBJECT *)0x0;
      goto LAB_08057bba;
    }
  }
  if (param_4 != (ASN1_GENERALIZEDTIME **)0x0) {
    return uVar4;
  }
LAB_08057c45:
  ASN1_GENERALIZEDTIME_free(s);
  return uVar4;
}

