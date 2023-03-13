
int PEM_bytes_read_bio(uchar **pdata,long *plen,char **pnm,char *name,BIO *bp,undefined1 *cb,void *u
                      )

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  uint uVar4;
  EVP_PKEY_ASN1_METHOD *pEVar5;
  int iVar6;
  int iVar7;
  EVP_CIPHER_INFO *cipher;
  EVP_CIPHER *str;
  char *pcVar8;
  char cVar9;
  undefined local_54 [4];
  char *local_50;
  EVP_CIPHER_INFO *local_4c;
  long local_48;
  ENGINE *local_44;
  EVP_CIPHER_INFO EStack_40;
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  local_54 = (undefined  [4])0x0;
  local_50 = (char *)0x0;
  local_4c = (EVP_CIPHER_INFO *)0x0;
  do {
    pcVar8 = (char *)(EVP_CIPHER_INFO *)local_54;
    iVar3 = PEM_read_bio(bp,(char **)(EVP_CIPHER_INFO *)local_54,&local_50,(uchar **)&local_4c,
                         &local_48);
    str = (EVP_CIPHER *)local_54;
    if (iVar3 == 0) {
      uVar4 = (*(code *)PTR_ERR_peek_error_006a6f54)();
      if ((uVar4 & 0xfff) == 0x6c) {
        pcVar8 = "Expecting: ";
        (*(code *)PTR_ERR_add_error_data_006a813c)(2,"Expecting: ",name);
      }
LAB_0056d2d4:
      if (local_2c == *(int *)puVar2) {
        return iVar3;
      }
      iVar3 = local_2c;
      (*(code *)PTR___stack_chk_fail_006a9ab0)();
      iVar6 = (*(code *)PTR_strlen_006a9a24)();
      iVar7 = (*(code *)PTR_strlen_006a9a24)(pcVar8);
      if (iVar7 + 1 < iVar6) {
        iVar7 = iVar3 + (iVar6 - iVar7);
        iVar6 = (*(code *)PTR_strcmp_006a9b18)(iVar7,pcVar8);
        if (iVar6 == 0) {
          if (*(char *)(iVar7 + -1) != ' ') {
            return 0;
          }
          return (iVar7 + -1) - iVar3;
        }
      }
      return 0;
    }
    iVar3 = (*(code *)PTR_strcmp_006a9b18)(local_54,name);
    if (iVar3 == 0) goto LAB_0056d288;
    iVar3 = (*(code *)PTR_strcmp_006a9b18)(name,"ANY PRIVATE KEY");
    if (iVar3 == 0) {
      iVar3 = (*(code *)PTR_strcmp_006a9b18)(str,"ENCRYPTED PRIVATE KEY");
      if ((iVar3 == 0) || (iVar3 = (*(code *)PTR_strcmp_006a9b18)(str,"PRIVATE KEY"), iVar3 == 0))
      goto LAB_0056d288;
      iVar3 = (*(code *)PTR_strlen_006a9a24)(str);
      if (0xc < iVar3) {
        pcVar8 = (char *)((int)str + iVar3 + -0xb);
        iVar3 = (*(code *)PTR_strcmp_006a9b18)(pcVar8,"PRIVATE KEY");
        if ((((iVar3 == 0) && (pcVar8[-1] == ' ')) && (0 < (int)(pcVar8 + (-1 - (int)str)))) &&
           (pEVar5 = EVP_PKEY_asn1_find_str
                               ((ENGINE **)0x0,(char *)str,(int)(pcVar8 + (-1 - (int)str))),
           str = (EVP_CIPHER *)local_54, pEVar5 != (EVP_PKEY_ASN1_METHOD *)0x0)) {
          iVar3 = *(int *)(pEVar5 + 0x5c);
joined_r0x0056d604:
          str = (EVP_CIPHER *)local_54;
          if (iVar3 != 0) goto LAB_0056d288;
        }
      }
    }
    else {
      iVar3 = (*(code *)PTR_strcmp_006a9b18)(name,"PARAMETERS");
      if (iVar3 != 0) {
        iVar3 = (*(code *)PTR_strcmp_006a9b18)(str,"X509 CERTIFICATE");
        if (((iVar3 == 0) &&
            (iVar6 = (*(code *)PTR_strcmp_006a9b18)(name,"CERTIFICATE"), iVar6 == 0)) ||
           ((iVar6 = (*(code *)PTR_strcmp_006a9b18)(str,"NEW CERTIFICATE REQUEST"), iVar6 == 0 &&
            (iVar6 = (*(code *)PTR_strcmp_006a9b18)(name,"CERTIFICATE REQUEST"), iVar6 == 0)))) {
LAB_0056d288:
          cipher = &EStack_40;
          iVar3 = PEM_get_EVP_CIPHER_INFO(local_50,cipher);
          pcVar8 = (char *)local_4c;
        }
        else {
          iVar6 = (*(code *)PTR_strcmp_006a9b18)(str,"CERTIFICATE");
          if (iVar6 == 0) {
            iVar3 = (*(code *)PTR_strcmp_006a9b18)(name,"TRUSTED CERTIFICATE");
            if ((iVar3 != 0) && (iVar3 = (*(code *)PTR_strcmp_006a9b18)(name,"PKCS7"), iVar3 != 0))
            {
              if (*name == 'C') {
                cVar9 = name[1];
                if (((cVar9 == 'M') && (name[2] == 'S')) && (name[3] == '\0')) goto LAB_0056d288;
                iVar3 = (*(code *)PTR_strcmp_006a9b18)(str,"PKCS7");
                if (iVar3 == 0) goto LAB_0056d264;
              }
              goto LAB_0056d1e0;
            }
            goto LAB_0056d288;
          }
          if ((iVar3 != 0) ||
             (iVar3 = (*(code *)PTR_strcmp_006a9b18)(name,"TRUSTED CERTIFICATE"), iVar3 != 0)) {
            iVar3 = (*(code *)PTR_strcmp_006a9b18)(str,"PKCS #7 SIGNED DATA");
            if ((iVar3 != 0) || (iVar3 = (*(code *)PTR_strcmp_006a9b18)(name,"PKCS7"), iVar3 != 0))
            {
              iVar3 = (*(code *)PTR_strcmp_006a9b18)(str,"PKCS7");
              if ((iVar3 == 0) && (*name == 'C')) {
                cVar9 = name[1];
LAB_0056d264:
                if (((cVar9 == 'M') && (name[2] == 'S')) && (name[3] == '\0')) goto LAB_0056d288;
              }
              goto LAB_0056d1e0;
            }
            goto LAB_0056d288;
          }
          cipher = &EStack_40;
          iVar3 = PEM_get_EVP_CIPHER_INFO(local_50,cipher);
          pcVar8 = (char *)local_4c;
        }
        local_4c = (EVP_CIPHER_INFO *)pcVar8;
        if ((iVar3 == 0) ||
           (iVar3 = PEM_do_header(&EStack_40,(uchar *)pcVar8,&local_48,cb,u),
           cipher = (EVP_CIPHER_INFO *)pcVar8, iVar3 == 0)) {
          iVar3 = 0;
          (*(code *)PTR_CRYPTO_free_006a6e88)(local_54);
          (*(code *)PTR_CRYPTO_free_006a6e88)(local_50);
          (*(code *)PTR_CRYPTO_free_006a6e88)(local_4c);
          pcVar8 = (char *)cipher;
        }
        else {
          *pdata = (uchar *)local_4c;
          *plen = local_48;
          puVar1 = PTR_CRYPTO_free_006a6e88;
          if (pnm == (char **)0x0) {
            iVar3 = 1;
            (*(code *)PTR_CRYPTO_free_006a6e88)(local_54);
            (*(code *)PTR_CRYPTO_free_006a6e88)(local_50);
          }
          else {
            iVar3 = 1;
            *pnm = (char *)local_54;
            (*(code *)puVar1)(local_50);
          }
        }
        goto LAB_0056d2d4;
      }
      iVar3 = (*(code *)PTR_strlen_006a9a24)(str);
      if (0xb < iVar3) {
        pcVar8 = (char *)((int)str + iVar3 + -10);
        iVar3 = (*(code *)PTR_strcmp_006a9b18)(pcVar8,"PARAMETERS");
        if (((iVar3 == 0) && (pcVar8[-1] == ' ')) &&
           ((0 < (int)(pcVar8 + (-1 - (int)str)) &&
            (pEVar5 = EVP_PKEY_asn1_find_str(&local_44,(char *)str,(int)(pcVar8 + (-1 - (int)str))),
            str = (EVP_CIPHER *)local_54, pEVar5 != (EVP_PKEY_ASN1_METHOD *)0x0)))) {
          iVar3 = *(int *)(pEVar5 + 0x38);
          if (local_44 != (ENGINE *)0x0) {
            (*(code *)PTR_ENGINE_finish_006a6fc4)();
          }
          goto joined_r0x0056d604;
        }
      }
    }
LAB_0056d1e0:
    (*(code *)PTR_CRYPTO_free_006a6e88)(str);
    (*(code *)PTR_CRYPTO_free_006a6e88)(local_50);
    (*(code *)PTR_CRYPTO_free_006a6e88)(local_4c);
  } while( true );
}

