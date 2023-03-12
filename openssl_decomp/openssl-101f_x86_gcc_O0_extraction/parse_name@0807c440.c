
X509_NAME * parse_name(char *param_1,int param_2,int param_3)

{
  char *pcVar1;
  char cVar2;
  uchar *bytes;
  size_t sVar3;
  char *ptr;
  void *ptr_00;
  void *ptr_01;
  undefined4 *ptr_02;
  char *pcVar4;
  char *pcVar5;
  int iVar6;
  char *pcVar7;
  X509_NAME *name;
  int iVar8;
  int iVar9;
  
  sVar3 = strlen(param_1);
  iVar9 = (sVar3 + 1 >> 1) * 4 + 4;
  ptr = (char *)CRYPTO_malloc(sVar3 + 1,"apps.c",0x84b);
  ptr_00 = CRYPTO_malloc(iVar9,"apps.c",0x84d);
  ptr_01 = CRYPTO_malloc(iVar9,"apps.c",0x84e);
  ptr_02 = (undefined4 *)CRYPTO_malloc(iVar9,"apps.c",0x84f);
  if ((((ptr != (char *)0x0) && (ptr_00 != (void *)0x0)) && (ptr_01 != (void *)0x0)) &&
     (ptr_02 != (undefined4 *)0x0)) {
    if (*param_1 == '/') {
      pcVar7 = param_1 + 1;
      *ptr_02 = 0;
      if (param_1[1] == '\0') {
        name = X509_NAME_new();
        if (name != (X509_NAME *)0x0) {
LAB_0807c7ca:
          CRYPTO_free(ptr_01);
          CRYPTO_free(ptr_00);
          CRYPTO_free(ptr);
          CRYPTO_free(ptr_02);
          return name;
        }
      }
      else {
        iVar9 = 0;
        pcVar5 = ptr;
        do {
          *(char **)((int)ptr_00 + iVar9 * 4) = pcVar5;
          while( true ) {
            while( true ) {
              pcVar4 = pcVar5 + 1;
              cVar2 = *pcVar7;
              if (cVar2 == '\0') goto LAB_0807c5f8;
              if (cVar2 != '\\') break;
              pcVar1 = pcVar7 + 1;
              if (*pcVar1 == '\0') goto LAB_0807c768;
              pcVar7 = pcVar7 + 2;
              *pcVar5 = *pcVar1;
              pcVar5 = pcVar4;
            }
            if (cVar2 == '=') break;
            pcVar7 = pcVar7 + 1;
            *pcVar5 = cVar2;
            pcVar5 = pcVar4;
          }
          *pcVar5 = '\0';
          pcVar1 = pcVar7 + 1;
          pcVar7 = pcVar7 + 1;
          if (*pcVar1 == '\0') {
LAB_0807c5f8:
            name = (X509_NAME *)0x0;
            BIO_printf(bio_err,
                       "end of string encountered while processing type of subject name element #%d\n"
                       ,iVar9);
            goto LAB_0807c4f6;
          }
          *(char **)((int)ptr_01 + iVar9 * 4) = pcVar4;
          pcVar5 = pcVar5 + 2;
          while( true ) {
            cVar2 = *pcVar7;
            if (cVar2 == '\0') break;
            if (cVar2 == '\\') {
              pcVar4 = pcVar7 + 1;
              if (*pcVar4 == '\0') goto LAB_0807c768;
              pcVar7 = pcVar7 + 2;
              pcVar5[-1] = *pcVar4;
            }
            else {
              if (cVar2 == '/') {
                pcVar7 = pcVar7 + 1;
                ptr_02[iVar9 + 1] = 0;
                break;
              }
              if ((param_3 != 0) && (cVar2 == '+')) {
                pcVar7 = pcVar7 + 1;
                ptr_02[iVar9 + 1] = 0xffffffff;
                break;
              }
              pcVar7 = pcVar7 + 1;
              pcVar5[-1] = cVar2;
            }
            pcVar5 = pcVar5 + 1;
          }
          pcVar5[-1] = '\0';
          iVar9 = iVar9 + 1;
        } while (*pcVar7 != '\0');
        name = X509_NAME_new();
        if (name != (X509_NAME *)0x0) {
          iVar8 = 0;
          do {
            iVar6 = OBJ_txt2nid(*(char **)((int)ptr_00 + iVar8 * 4));
            if (iVar6 == 0) {
              BIO_printf(bio_err,"Subject Attribute %s has no known NID, skipped\n",
                         *(undefined4 *)((int)ptr_00 + iVar8 * 4));
            }
            else {
              bytes = *(uchar **)((int)ptr_01 + iVar8 * 4);
              if (*bytes == '\0') {
                BIO_printf(bio_err,"No value provided for Subject Attribute %s, skipped\n",
                           *(undefined4 *)((int)ptr_00 + iVar8 * 4));
              }
              else {
                iVar6 = X509_NAME_add_entry_by_NID(name,iVar6,param_2,bytes,-1,-1,ptr_02[iVar8]);
                if (iVar6 == 0) goto LAB_0807c4f6;
              }
            }
            iVar8 = iVar8 + 1;
          } while (iVar9 != iVar8);
          goto LAB_0807c7ca;
        }
      }
      name = (X509_NAME *)0x0;
    }
    else {
      name = (X509_NAME *)0x0;
      BIO_printf(bio_err,"Subject does not start with \'/\'.\n");
    }
    goto LAB_0807c4f6;
  }
  BIO_printf(bio_err,"malloc error\n");
  X509_NAME_free((X509_NAME *)0x0);
  if (ptr_01 == (void *)0x0) goto LAB_0807c50e;
LAB_0807c502:
  CRYPTO_free(ptr_01);
LAB_0807c50e:
  if (ptr_00 != (void *)0x0) {
    CRYPTO_free(ptr_00);
  }
  if (ptr_02 != (undefined4 *)0x0) {
    CRYPTO_free(ptr_02);
  }
  if (ptr != (char *)0x0) {
    CRYPTO_free(ptr);
  }
  return (X509_NAME *)0x0;
LAB_0807c768:
  name = (X509_NAME *)0x0;
  BIO_printf(bio_err,"escape character at end of string\n");
LAB_0807c4f6:
  X509_NAME_free(name);
  goto LAB_0807c502;
}

