
TXT_DB * TXT_DB_read(BIO *in,int num)

{
  BUF_MEM *str;
  int iVar1;
  _STACK *p_Var2;
  lhash_st_OPENSSL_STRING **pplVar3;
  _func_4743 *p_Var4;
  size_t sVar5;
  int iVar6;
  undefined4 *data;
  byte *pbVar7;
  byte *pbVar8;
  uint uVar9;
  char *__s;
  char *pcVar10;
  undefined4 *puVar11;
  TXT_DB *ptr;
  uint uVar12;
  size_t len;
  undefined4 *puVar13;
  
  str = BUF_MEM_new();
  if (((str == (BUF_MEM *)0x0) || (iVar1 = BUF_MEM_grow(str,0x200), iVar1 == 0)) ||
     (ptr = (TXT_DB *)CRYPTO_malloc(0x20,"txt_db.c",0x57), ptr == (TXT_DB *)0x0)) {
    ptr = (TXT_DB *)0x0;
  }
  else {
    ptr->num_fields = num;
    ptr->index = (lhash_st_OPENSSL_STRING **)0x0;
    ptr->qual = (_func_4743 *)0x0;
    p_Var2 = sk_new_null();
    ptr->data = (stack_st_OPENSSL_PSTRING *)p_Var2;
    if (p_Var2 != (_STACK *)0x0) {
      pplVar3 = (lhash_st_OPENSSL_STRING **)CRYPTO_malloc(num << 2,"txt_db.c",0x5e);
      ptr->index = pplVar3;
      if (pplVar3 != (lhash_st_OPENSSL_STRING **)0x0) {
        p_Var4 = (_func_4743 *)CRYPTO_malloc(num << 2,"txt_db.c",0x60);
        ptr->qual = p_Var4;
        if (p_Var4 != (_func_4743 *)0x0) {
          if (0 < num) {
            iVar1 = 0;
            do {
              ptr->index[iVar1] = (lhash_st_OPENSSL_STRING *)0x0;
              *(undefined4 *)(ptr->qual + iVar1 * 4) = 0;
              iVar1 = iVar1 + 1;
            } while (iVar1 != num);
          }
          uVar12 = 0;
          iVar1 = 1;
          len = 0x200;
          str->data[0x1ff] = '\0';
LAB_000db5c2:
          *str->data = (char)uVar12;
          BIO_gets(in,str->data,len);
          __s = str->data;
          if (*__s == '\0') {
LAB_000db62e:
            BUF_MEM_free(str);
            return ptr;
          }
          pcVar10 = __s;
          if (*__s == '#') goto LAB_000db5f0;
          do {
            sVar5 = strlen(__s);
            uVar12 = uVar12 + sVar5;
            if (pcVar10[uVar12 - 1] == '\n') {
              pcVar10[uVar12 - 1] = '\0';
              data = (undefined4 *)CRYPTO_malloc((num + 1) * 4 + uVar12,"txt_db.c",0x7e);
              if (data == (undefined4 *)0x0) break;
              iVar6 = 1;
              *data = data + num + 1;
              uVar12 = 0;
              pbVar7 = (byte *)str->data;
              puVar11 = data + num + 1;
              while( true ) {
                pbVar8 = pbVar7 + 1;
                uVar9 = (uint)*pbVar7;
                if (uVar9 == 0) break;
                if (uVar9 == 9) {
                  puVar13 = (undefined4 *)((int)puVar11 + 1);
                  if (uVar12 != 0) {
                    puVar11 = (undefined4 *)((int)puVar11 + -1);
                    goto LAB_000db666;
                  }
                  *(undefined *)puVar11 = 0;
                  puVar11 = puVar13;
                  pbVar7 = pbVar8;
                  if (num <= iVar6) break;
                  data[iVar6] = puVar13;
                  iVar6 = iVar6 + 1;
                }
                else {
LAB_000db666:
                  *(byte *)puVar11 = *pbVar7;
                  uVar12 = count_leading_zeroes(uVar9 - 0x5c);
                  uVar12 = uVar12 >> 5;
                  pbVar7 = pbVar8;
                  puVar11 = (undefined4 *)((int)puVar11 + 1);
                }
              }
              *(undefined *)puVar11 = 0;
              if ((iVar6 == num) && (uVar12 = (uint)*pbVar7, uVar12 == 0)) {
                data[num] = (undefined *)((int)puVar11 + 1);
                iVar6 = sk_push((_STACK *)ptr->data,data);
                if (iVar6 != 0) goto LAB_000db5f0;
                fwrite("failure in sk_push\n",1,0x13,stderr);
              }
              else {
                __fprintf_chk(stderr,1,
                              "wrong number of fields on line %ld (looking for field %d, got %d, \'%s\' left)\n"
                              ,iVar1,num,iVar6,pbVar7);
              }
              BUF_MEM_free(str);
              goto LAB_000db502;
            }
LAB_000db5f0:
            iVar1 = iVar1 + 1;
            if (uVar12 == 0) goto LAB_000db5c2;
            len = len + 0x200;
            iVar6 = BUF_MEM_grow_clean(str,len);
            if (iVar6 == 0) break;
            str->data[uVar12] = '\0';
            BIO_gets(in,str->data + uVar12,len - uVar12);
            pcVar10 = str->data;
            __s = pcVar10 + uVar12;
            if (pcVar10[uVar12] == '\0') goto LAB_000db62e;
          } while( true );
        }
      }
    }
  }
  BUF_MEM_free(str);
  fwrite("OPENSSL_malloc failure\n",1,0x17,stderr);
  if (ptr != (TXT_DB *)0x0) {
LAB_000db502:
    if ((_STACK *)ptr->data != (_STACK *)0x0) {
      sk_free((_STACK *)ptr->data);
    }
    if (ptr->index != (lhash_st_OPENSSL_STRING **)0x0) {
      CRYPTO_free(ptr->index);
    }
    if (ptr->qual != (_func_4743 *)0x0) {
      CRYPTO_free(ptr->qual);
    }
    CRYPTO_free(ptr);
    ptr = (TXT_DB *)0x0;
  }
  return ptr;
}

