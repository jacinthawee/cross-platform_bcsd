
int PEM_bytes_read_bio(uchar **pdata,long *plen,char **pnm,char *name,BIO *bp,undefined1 *cb,void *u
                      )

{
  int iVar1;
  size_t sVar2;
  char *__s1;
  int iVar3;
  int iVar4;
  ulong uVar5;
  EVP_PKEY_ASN1_METHOD *pEVar6;
  char *pcVar7;
  char *local_54;
  char *local_50;
  uchar *local_4c;
  long local_48;
  ENGINE *local_44;
  EVP_CIPHER_INFO EStack_40;
  int local_2c;
  
  local_2c = __stack_chk_guard;
  local_54 = (char *)0x0;
  local_50 = (char *)0x0;
  local_4c = (uchar *)0x0;
  do {
    iVar1 = PEM_read_bio(bp,&local_54,&local_50,&local_4c,&local_48);
    __s1 = local_54;
    if (iVar1 == 0) {
      uVar5 = ERR_peek_error();
      if ((uVar5 & 0xfff) == 0x6c) {
        ERR_add_error_data(2,"Expecting: ",name);
      }
LAB_000c269c:
      if (local_2c == __stack_chk_guard) {
        return iVar1;
      }
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    iVar1 = strcmp(local_54,name);
    if (iVar1 == 0) goto LAB_000c267a;
    iVar1 = strcmp(name,"ANY PRIVATE KEY");
    if (iVar1 == 0) {
      iVar1 = strcmp(__s1,"ENCRYPTED PRIVATE KEY");
      if ((iVar1 == 0) || (iVar1 = strcmp(__s1,"PRIVATE KEY"), iVar1 == 0)) goto LAB_000c267a;
      sVar2 = strlen(__s1);
      if (0xc < (int)sVar2) {
        pcVar7 = __s1 + (sVar2 - 0xb);
        iVar1 = strcmp(pcVar7,"PRIVATE KEY");
        if (((iVar1 == 0) && (pcVar7[-1] == ' ')) &&
           ((0 < (int)(pcVar7 + (-1 - (int)__s1)) &&
            (pEVar6 = EVP_PKEY_asn1_find_str((ENGINE **)0x0,__s1,(int)(pcVar7 + (-1 - (int)__s1))),
            __s1 = local_54, pEVar6 != (EVP_PKEY_ASN1_METHOD *)0x0)))) {
          iVar1 = *(int *)(pEVar6 + 0x5c);
joined_r0x000c2844:
          __s1 = local_54;
          if (iVar1 != 0) goto LAB_000c267a;
        }
      }
    }
    else {
      iVar1 = strcmp(name,"PARAMETERS");
      if (iVar1 != 0) {
        iVar1 = strcmp(__s1,"X509 CERTIFICATE");
        if ((((((iVar1 == 0) && (iVar3 = strcmp(name,"CERTIFICATE"), iVar3 == 0)) ||
              ((iVar3 = strcmp(__s1,"NEW CERTIFICATE REQUEST"), iVar3 == 0 &&
               (iVar3 = strcmp(name,"CERTIFICATE REQUEST"), iVar3 == 0)))) ||
             ((iVar3 = strcmp(__s1,"CERTIFICATE"), iVar3 == 0 &&
              (iVar4 = strcmp(name,"TRUSTED CERTIFICATE"), iVar4 == 0)))) ||
            ((iVar1 == 0 && (iVar1 = strcmp(name,"TRUSTED CERTIFICATE"), iVar1 == 0)))) ||
           ((iVar3 == 0 && (iVar1 = strcmp(name,"PKCS7"), iVar1 == 0)))) {
LAB_000c267a:
          iVar1 = PEM_get_EVP_CIPHER_INFO(local_50,&EStack_40);
        }
        else {
          iVar1 = strcmp(__s1,"PKCS #7 SIGNED DATA");
          if ((iVar1 != 0) || (iVar1 = strcmp(name,"PKCS7"), iVar1 != 0)) {
            if (((((iVar3 != 0) || (*name != 'C')) || (name[1] != 'M')) ||
                ((name[2] != 'S' || (name[3] != '\0')))) &&
               ((iVar1 = strcmp(__s1,"PKCS7"), iVar1 != 0 ||
                (((*name != 'C' || (name[1] != 'M')) || ((name[2] != 'S' || (name[3] != '\0'))))))))
            goto LAB_000c2602;
            goto LAB_000c267a;
          }
          iVar1 = PEM_get_EVP_CIPHER_INFO(local_50,&EStack_40);
        }
        if ((iVar1 == 0) || (iVar1 = PEM_do_header(&EStack_40,local_4c,&local_48,cb,u), iVar1 == 0))
        {
          iVar1 = 0;
          CRYPTO_free(local_54);
          CRYPTO_free(local_50);
          CRYPTO_free(local_4c);
        }
        else {
          *pdata = local_4c;
          *plen = local_48;
          if (pnm == (char **)0x0) {
            iVar1 = 1;
            CRYPTO_free(local_54);
            CRYPTO_free(local_50);
          }
          else {
            iVar1 = 1;
            *pnm = local_54;
            CRYPTO_free(local_50);
          }
        }
        goto LAB_000c269c;
      }
      sVar2 = strlen(__s1);
      if (0xb < (int)sVar2) {
        pcVar7 = __s1 + (sVar2 - 10);
        iVar1 = strcmp(pcVar7,"PARAMETERS");
        if ((((iVar1 == 0) && (pcVar7[-1] == ' ')) && (0 < (int)(pcVar7 + (-1 - (int)__s1)))) &&
           (pEVar6 = EVP_PKEY_asn1_find_str(&local_44,__s1,(int)(pcVar7 + (-1 - (int)__s1))),
           __s1 = local_54, pEVar6 != (EVP_PKEY_ASN1_METHOD *)0x0)) {
          iVar1 = *(int *)(pEVar6 + 0x38);
          if (local_44 != (ENGINE *)0x0) {
            ENGINE_finish(local_44);
          }
          goto joined_r0x000c2844;
        }
      }
    }
LAB_000c2602:
    CRYPTO_free(__s1);
    CRYPTO_free(local_50);
    CRYPTO_free(local_4c);
  } while( true );
}

