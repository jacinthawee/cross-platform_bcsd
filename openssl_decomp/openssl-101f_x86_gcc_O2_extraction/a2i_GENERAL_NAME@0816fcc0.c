
GENERAL_NAME *
a2i_GENERAL_NAME(GENERAL_NAME *out,X509V3_EXT_METHOD *method,X509V3_CTX *ctx,int gen_type,
                char *value,int is_nc)

{
  ASN1_STRING *str;
  size_t sVar1;
  X509_NAME *a;
  stack_st_CONF_VALUE *dn_sk;
  char *pcVar2;
  OTHERNAME *pOVar3;
  ASN1_TYPE *pAVar4;
  ASN1_OCTET_STRING *pAVar5;
  ASN1_OBJECT *pAVar6;
  GENERAL_NAME *a_00;
  int iVar7;
  int iVar8;
  
  if (value == (char *)0x0) {
    iVar8 = 0x1b1;
    iVar7 = 0x7c;
LAB_0816ffd6:
    ERR_put_error(0x22,0xa4,iVar7,"v3_alt.c",iVar8);
    return (GENERAL_NAME *)0x0;
  }
  a_00 = out;
  if ((out == (GENERAL_NAME *)0x0) && (a_00 = GENERAL_NAME_new(), a_00 == (GENERAL_NAME *)0x0)) {
    iVar8 = 0x1bc;
    iVar7 = 0x41;
    goto LAB_0816ffd6;
  }
  switch(gen_type) {
  case 0:
    pcVar2 = strchr(value,0x3b);
    if (pcVar2 != (char *)0x0) {
      pOVar3 = OTHERNAME_new();
      (a_00->d).otherName = pOVar3;
      if (pOVar3 != (OTHERNAME *)0x0) {
        ASN1_TYPE_free(pOVar3->value);
        pOVar3 = (a_00->d).otherName;
        pAVar4 = ASN1_generate_v3(pcVar2 + 1,ctx);
        pOVar3->value = pAVar4;
        if (pAVar4 != (ASN1_TYPE *)0x0) {
          sVar1 = (int)pcVar2 - (int)value;
          pcVar2 = (char *)CRYPTO_malloc(sVar1 + 1,"v3_alt.c",0x245);
          strncpy(pcVar2,value,sVar1);
          pcVar2[sVar1] = '\0';
          pOVar3 = (a_00->d).otherName;
          pAVar6 = OBJ_txt2obj(pcVar2,0);
          pOVar3->type_id = pAVar6;
          CRYPTO_free(pcVar2);
          if (((a_00->d).otherName)->type_id != (ASN1_OBJECT *)0x0) goto LAB_0816fde8;
        }
      }
    }
    ERR_put_error(0x22,0xa4,0x93,"v3_alt.c",0x1ee);
    break;
  case 1:
  case 2:
  case 6:
    str = ASN1_STRING_type_new(0x16);
    (a_00->d).otherName = (OTHERNAME *)str;
    if (str != (ASN1_STRING *)0x0) {
      sVar1 = strlen(value);
      iVar7 = ASN1_STRING_set(str,value,sVar1);
      if (iVar7 != 0) goto LAB_0816fde8;
    }
    ERR_put_error(0x22,0xa4,0x41,"v3_alt.c",0x1fd);
    break;
  default:
    ERR_put_error(0x22,0xa4,0xa7,"v3_alt.c",499);
    break;
  case 4:
    a = X509_NAME_new();
    if (a != (X509_NAME *)0x0) {
      dn_sk = X509V3_get_section(ctx,value);
      if (dn_sk == (stack_st_CONF_VALUE *)0x0) {
        ERR_put_error(0x22,0x90,0x96,"v3_alt.c",0x259);
        ERR_add_error_data(2,"section=",value);
        X509_NAME_free(a);
      }
      else {
        iVar7 = X509V3_NAME_from_section(a,dn_sk,0x1001);
        if (iVar7 != 0) {
          (a_00->d).directoryName = a;
          X509V3_section_free(ctx,dn_sk);
          goto LAB_0816fde8;
        }
        X509_NAME_free(a);
        (a_00->d).directoryName = a;
        X509V3_section_free(ctx,dn_sk);
      }
    }
    ERR_put_error(0x22,0xa4,0x95,"v3_alt.c",0x1e6);
    break;
  case 7:
    if (is_nc == 0) {
      pAVar5 = a2i_IPADDRESS(value);
      (a_00->d).iPAddress = pAVar5;
    }
    else {
      pAVar5 = a2i_IPADDRESS_NC(value);
      (a_00->d).iPAddress = pAVar5;
    }
    if (pAVar5 != (ASN1_OCTET_STRING *)0x0) {
LAB_0816fde8:
      a_00->type = gen_type;
      return a_00;
    }
    iVar8 = 0x1dd;
    iVar7 = 0x76;
    goto LAB_0816ff22;
  case 8:
    pAVar6 = OBJ_txt2obj(value,0);
    if (pAVar6 != (ASN1_OBJECT *)0x0) {
      (a_00->d).registeredID = pAVar6;
      goto LAB_0816fde8;
    }
    iVar8 = 0x1ce;
    iVar7 = 0x77;
LAB_0816ff22:
    ERR_put_error(0x22,0xa4,iVar7,"v3_alt.c",iVar8);
    ERR_add_error_data(2,"value=",value);
  }
  if (out != (GENERAL_NAME *)0x0) {
    return (GENERAL_NAME *)0x0;
  }
  GENERAL_NAME_free(a_00);
  return (GENERAL_NAME *)0x0;
}

