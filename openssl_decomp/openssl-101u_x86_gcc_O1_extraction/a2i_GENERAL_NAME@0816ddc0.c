
GENERAL_NAME *
a2i_GENERAL_NAME(GENERAL_NAME *out,X509V3_EXT_METHOD *method,X509V3_CTX *ctx,int gen_type,
                char *value,int is_nc)

{
  ASN1_STRING *str;
  size_t sVar1;
  ASN1_OBJECT *pAVar2;
  char *pcVar3;
  OTHERNAME *pOVar4;
  ASN1_TYPE *pAVar5;
  X509_NAME *nm;
  stack_st_CONF_VALUE *dn_sk;
  ASN1_OCTET_STRING *pAVar6;
  GENERAL_NAME *a;
  int iVar7;
  int iVar8;
  
  if (value == (char *)0x0) {
    iVar8 = 0x1b5;
    iVar7 = 0x7c;
LAB_0816e116:
    ERR_put_error(0x22,0xa4,iVar7,"v3_alt.c",iVar8);
    return (GENERAL_NAME *)0x0;
  }
  a = out;
  if ((out == (GENERAL_NAME *)0x0) && (a = GENERAL_NAME_new(), a == (GENERAL_NAME *)0x0)) {
    iVar8 = 0x1be;
    iVar7 = 0x41;
    goto LAB_0816e116;
  }
  switch(gen_type) {
  case 0:
    pcVar3 = strchr(value,0x3b);
    if (pcVar3 != (char *)0x0) {
      pOVar4 = OTHERNAME_new();
      (a->d).otherName = pOVar4;
      if (pOVar4 != (OTHERNAME *)0x0) {
        ASN1_TYPE_free(pOVar4->value);
        pOVar4 = (a->d).otherName;
        pAVar5 = ASN1_generate_v3(pcVar3 + 1,ctx);
        pOVar4->value = pAVar5;
        if (pAVar5 != (ASN1_TYPE *)0x0) {
          sVar1 = (int)pcVar3 - (int)value;
          pcVar3 = (char *)CRYPTO_malloc(sVar1 + 1,"v3_alt.c",0x23f);
          strncpy(pcVar3,value,sVar1);
          pcVar3[sVar1] = '\0';
          pOVar4 = (a->d).otherName;
          pAVar2 = OBJ_txt2obj(pcVar3,0);
          pOVar4->type_id = pAVar2;
          CRYPTO_free(pcVar3);
          if (((a->d).otherName)->type_id != (ASN1_OBJECT *)0x0) goto LAB_0816de89;
        }
      }
    }
    ERR_put_error(0x22,0xa4,0x93,"v3_alt.c",0x1eb);
    break;
  case 1:
  case 2:
  case 6:
    str = ASN1_STRING_type_new(0x16);
    (a->d).otherName = (OTHERNAME *)str;
    if (str != (ASN1_STRING *)0x0) {
      sVar1 = strlen(value);
      iVar7 = ASN1_STRING_set(str,value,sVar1);
      if (iVar7 != 0) goto LAB_0816de89;
    }
    ERR_put_error(0x22,0xa4,0x41,"v3_alt.c",0x1f8);
    break;
  default:
    ERR_put_error(0x22,0xa4,0xa7,"v3_alt.c",0x1f0);
    break;
  case 4:
    nm = X509_NAME_new();
    if (nm == (X509_NAME *)0x0) {
      dn_sk = (stack_st_CONF_VALUE *)0x0;
    }
    else {
      dn_sk = X509V3_get_section(ctx,value);
      if (dn_sk == (stack_st_CONF_VALUE *)0x0) {
        ERR_put_error(0x22,0x90,0x96,"v3_alt.c",0x252);
        ERR_add_error_data(2,"section=",value);
      }
      else {
        iVar7 = X509V3_NAME_from_section(nm,dn_sk,0x1001);
        if (iVar7 != 0) {
          (a->d).directoryName = nm;
          X509V3_section_free(ctx,dn_sk);
          goto LAB_0816de89;
        }
      }
    }
    X509_NAME_free(nm);
    X509V3_section_free(ctx,dn_sk);
    ERR_put_error(0x22,0xa4,0x95,"v3_alt.c",0x1e4);
    break;
  case 7:
    if (is_nc == 0) {
      pAVar6 = a2i_IPADDRESS(value);
      (a->d).iPAddress = pAVar6;
    }
    else {
      pAVar6 = a2i_IPADDRESS_NC(value);
      (a->d).iPAddress = pAVar6;
    }
    if (pAVar6 != (ASN1_OCTET_STRING *)0x0) {
LAB_0816de89:
      a->type = gen_type;
      return a;
    }
    iVar8 = 0x1dc;
    iVar7 = 0x76;
    goto LAB_0816e062;
  case 8:
    pAVar2 = OBJ_txt2obj(value,0);
    if (pAVar2 != (ASN1_OBJECT *)0x0) {
      (a->d).registeredID = pAVar2;
      goto LAB_0816de89;
    }
    iVar8 = 0x1ce;
    iVar7 = 0x77;
LAB_0816e062:
    ERR_put_error(0x22,0xa4,iVar7,"v3_alt.c",iVar8);
    ERR_add_error_data(2,"value=",value);
  }
  if (out != (GENERAL_NAME *)0x0) {
    return (GENERAL_NAME *)0x0;
  }
  GENERAL_NAME_free(a);
  return (GENERAL_NAME *)0x0;
}

