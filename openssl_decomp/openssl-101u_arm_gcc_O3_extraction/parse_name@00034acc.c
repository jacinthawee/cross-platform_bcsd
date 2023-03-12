
X509_NAME * parse_name(char *param_1,int param_2,int param_3)

{
  byte *pbVar1;
  bool bVar2;
  size_t sVar3;
  X509_NAME *ptr;
  char **ptr_00;
  void *ptr_01;
  X509_NAME **ptr_02;
  X509_NAME **ppXVar4;
  char *pcVar5;
  X509_NAME *pXVar6;
  byte bVar7;
  X509_NAME *pXVar8;
  byte *pbVar9;
  int iVar10;
  char **ppcVar11;
  X509_NAME *pXVar12;
  X509_NAME **ppXVar13;
  X509_NAME *name;
  char *pcVar14;
  X509_NAME **ppXVar15;
  
  sVar3 = strlen(param_1);
  ptr = (X509_NAME *)CRYPTO_malloc(sVar3 + 1,"apps.c",0x7ee);
  iVar10 = ((sVar3 + 1 >> 1) + 1) * 4;
  ptr_00 = (char **)CRYPTO_malloc(iVar10,"apps.c",0x7f0);
  ptr_01 = CRYPTO_malloc(iVar10,"apps.c",0x7f1);
  ptr_02 = (X509_NAME **)CRYPTO_malloc(iVar10,"apps.c",0x7f2);
  if (ptr_00 != (char **)0x0 && ptr != (X509_NAME *)0x0) {
    bVar2 = ptr_02 == (X509_NAME **)0x0 || ptr_01 == (void *)0x0;
    name = (X509_NAME *)(uint)bVar2;
    if (ptr_02 != (X509_NAME **)0x0 && ptr_01 != (void *)0x0) {
      if (*param_1 == '/') {
        *ptr_02 = name;
        pbVar9 = (byte *)(param_1 + 1);
        if (param_1[1] != '\0') {
          ppXVar13 = (X509_NAME **)(ptr_00 + -1);
          ppXVar15 = (X509_NAME **)((int)ptr_01 + -4);
          ppXVar4 = ptr_02;
          pXVar6 = ptr;
          pXVar12 = name;
LAB_00034bde:
          ppXVar13 = ppXVar13 + 1;
          *ppXVar13 = pXVar6;
          do {
            pXVar8 = (X509_NAME *)((int)&pXVar6->entries + 1);
            bVar7 = *pbVar9;
            if (bVar7 == 0) goto LAB_00034c22;
            if (bVar7 == 0x5c) {
              bVar7 = pbVar9[1];
              pbVar9 = pbVar9 + 2;
              if (bVar7 == 0) goto LAB_00034c06;
            }
            else {
              if (bVar7 == 0x3d) goto LAB_00034c40;
              pbVar9 = pbVar9 + 1;
            }
            *(byte *)&pXVar6->entries = bVar7;
            pXVar6 = pXVar8;
          } while( true );
        }
        name = X509_NAME_new();
        if (name != (X509_NAME *)0x0) goto LAB_00034d70;
      }
      else {
        BIO_printf(bio_err,"Subject does not start with \'/\'.\n");
      }
      goto LAB_00034bb2;
    }
  }
  BIO_printf(bio_err,"malloc error\n");
  X509_NAME_free((X509_NAME *)0x0);
  if (ptr_01 != (void *)0x0) {
    CRYPTO_free(ptr_01);
  }
  goto LAB_00034b72;
LAB_00034c40:
  *(bool *)&pXVar6->entries = bVar2;
  pbVar9 = pbVar9 + 1;
  if (*pbVar9 == 0) {
LAB_00034c22:
    BIO_printf(bio_err,
               "end of string encountered while processing type of subject name element #%d\n",
               pXVar12);
    name = (X509_NAME *)0x0;
    goto LAB_00034bb2;
  }
  ppXVar15 = ppXVar15 + 1;
  *ppXVar15 = pXVar8;
  pcVar5 = (char *)((int)&pXVar6->entries + 2);
  if (param_3 == 0) {
    while( true ) {
      bVar7 = *pbVar9;
      pcVar14 = pcVar5 + -1;
      if (bVar7 == 0) break;
      if (bVar7 == 0x5c) {
        pbVar1 = pbVar9 + 1;
        pbVar9 = pbVar9 + 2;
        if (*pbVar1 == 0) goto LAB_00034c06;
        pcVar5[-1] = *pbVar1;
      }
      else {
        if (bVar7 == 0x2f) goto LAB_00034ca8;
        pbVar9 = pbVar9 + 1;
        pcVar5[-1] = bVar7;
      }
      pcVar5 = pcVar5 + 1;
    }
  }
  else {
    while( true ) {
      bVar7 = *pbVar9;
      pcVar14 = pcVar5 + -1;
      if (bVar7 == 0) break;
      if (bVar7 == 0x5c) {
        bVar7 = pbVar9[1];
        pbVar9 = pbVar9 + 2;
        if (bVar7 == 0) goto LAB_00034c06;
      }
      else {
        if (bVar7 == 0x2f) goto LAB_00034ca8;
        pbVar9 = pbVar9 + 1;
        if (bVar7 == 0x2b) {
          ppXVar4[1] = (X509_NAME *)0xffffffff;
          break;
        }
      }
      pcVar5[-1] = bVar7;
      pcVar5 = pcVar5 + 1;
    }
  }
LAB_00034cae:
  *pcVar14 = bVar2;
  pXVar6 = (X509_NAME *)(pcVar14 + 1);
  pXVar8 = (X509_NAME *)(uint)*pbVar9;
  pXVar12 = (X509_NAME *)((int)&pXVar12->entries + 1);
  ppXVar4 = ppXVar4 + 1;
  if (pXVar8 == (X509_NAME *)0x0) goto code_r0x00034cc2;
  goto LAB_00034bde;
LAB_00034ca8:
  pbVar9 = pbVar9 + 1;
  ppXVar4[1] = name;
  goto LAB_00034cae;
LAB_00034c06:
  name = (X509_NAME *)0x0;
  BIO_printf(bio_err,"escape character at end of string\n");
  goto LAB_00034bb2;
code_r0x00034cc2:
  name = X509_NAME_new();
  if (name != (X509_NAME *)0x0) {
    ppcVar11 = ptr_00;
    pXVar6 = pXVar8;
    if (pXVar12 != (X509_NAME *)0x0) {
      do {
        iVar10 = OBJ_txt2nid(*ppcVar11);
        if (iVar10 == 0) {
          BIO_printf(bio_err,"Subject Attribute %s has no known NID, skipped\n",*ppcVar11);
        }
        else if (**(uchar **)((int)ptr_01 + (int)pXVar8) == '\0') {
          BIO_printf(bio_err,"No value provided for Subject Attribute %s, skipped\n",*ppcVar11);
        }
        else {
          iVar10 = X509_NAME_add_entry_by_NID
                             (name,iVar10,param_2,*(uchar **)((int)ptr_01 + (int)pXVar8),-1,-1,
                              *(int *)((int)ptr_02 + (int)pXVar8));
          if (iVar10 == 0) goto LAB_00034bb2;
        }
        pXVar6 = (X509_NAME *)((int)&pXVar6->entries + 1);
        pXVar8 = (X509_NAME *)&pXVar8->modified;
        ppcVar11 = ppcVar11 + 1;
      } while (pXVar6 != pXVar12);
    }
LAB_00034d70:
    CRYPTO_free(ptr_01);
    CRYPTO_free(ptr_00);
    CRYPTO_free(ptr);
    CRYPTO_free(ptr_02);
    return name;
  }
LAB_00034bb2:
  X509_NAME_free(name);
  CRYPTO_free(ptr_01);
LAB_00034b72:
  if (ptr_00 != (char **)0x0) {
    CRYPTO_free(ptr_00);
  }
  if (ptr_02 != (X509_NAME **)0x0) {
    CRYPTO_free(ptr_02);
  }
  if (ptr != (X509_NAME *)0x0) {
    CRYPTO_free(ptr);
    ptr = (X509_NAME *)0x0;
  }
  return ptr;
}

