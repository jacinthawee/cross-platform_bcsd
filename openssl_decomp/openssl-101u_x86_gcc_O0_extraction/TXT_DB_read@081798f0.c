
TXT_DB * TXT_DB_read(BIO *in,int num)

{
  char cVar1;
  BUF_MEM *str;
  int iVar2;
  _STACK *p_Var3;
  lhash_st_OPENSSL_STRING **pplVar4;
  _func_4743 *p_Var5;
  int iVar6;
  char *pcVar7;
  size_t sVar8;
  undefined4 *data;
  char *pcVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  TXT_DB *ptr;
  size_t len;
  bool bVar12;
  int local_34;
  int local_30;
  
  str = BUF_MEM_new();
  if (((str == (BUF_MEM *)0x0) || (iVar2 = BUF_MEM_grow(str,0x200), iVar2 == 0)) ||
     (ptr = (TXT_DB *)CRYPTO_malloc(0x20,"txt_db.c",0x59), ptr == (TXT_DB *)0x0)) {
    ptr = (TXT_DB *)0x0;
  }
  else {
    ptr->index = (lhash_st_OPENSSL_STRING **)0x0;
    ptr->qual = (_func_4743 *)0x0;
    ptr->num_fields = num;
    p_Var3 = sk_new_null();
    ptr->data = (stack_st_OPENSSL_PSTRING *)p_Var3;
    if (p_Var3 != (_STACK *)0x0) {
      pplVar4 = (lhash_st_OPENSSL_STRING **)CRYPTO_malloc(num * 4,"txt_db.c",0x60);
      ptr->index = pplVar4;
      if (pplVar4 != (lhash_st_OPENSSL_STRING **)0x0) {
        p_Var5 = (_func_4743 *)CRYPTO_malloc(num * 4,"txt_db.c",0x62);
        ptr->qual = p_Var5;
        if (p_Var5 != (_func_4743 *)0x0) {
          iVar2 = 0;
          if (0 < num) {
            do {
              ptr->index[iVar2] = (lhash_st_OPENSSL_STRING *)0x0;
              *(undefined4 *)(ptr->qual + iVar2 * 4) = 0;
              iVar2 = iVar2 + 1;
            } while (num != iVar2);
          }
          iVar2 = 0;
          local_34 = 1;
          str->data[0x1ff] = '\0';
          len = 0x200;
          do {
            if (iVar2 == 0) {
              *str->data = '\0';
              BIO_gets(in,str->data,len);
              pcVar7 = str->data;
              if (*pcVar7 == '\0') goto LAB_08179c20;
              pcVar9 = pcVar7;
              if (*pcVar7 != '#') goto LAB_08179acb;
            }
            else {
              len = len + 0x200;
              iVar6 = BUF_MEM_grow_clean(str,len);
              if (iVar6 == 0) break;
              str->data[iVar2] = '\0';
              BIO_gets(in,str->data + iVar2,len - iVar2);
              pcVar7 = str->data + iVar2;
              pcVar9 = str->data;
              if (*pcVar7 == '\0') {
LAB_08179c20:
                BUF_MEM_free(str);
                return ptr;
              }
LAB_08179acb:
              sVar8 = strlen(pcVar7);
              iVar2 = iVar2 + sVar8;
              if (pcVar9[iVar2 + -1] == '\n') {
                pcVar9[iVar2 + -1] = '\0';
                data = (undefined4 *)CRYPTO_malloc(iVar2 + num * 4 + 4,"txt_db.c",0x7f);
                if (data == (undefined4 *)0x0) break;
                local_30 = 1;
                *data = data + num + 1;
                bVar12 = false;
                puVar10 = data + num + 1;
                pcVar7 = str->data;
                while( true ) {
                  pcVar9 = pcVar7 + 1;
                  cVar1 = *pcVar7;
                  puVar11 = puVar10;
                  if (cVar1 == '\0') break;
                  pcVar7 = pcVar9;
                  if (cVar1 == '\t') {
                    if (bVar12) {
                      puVar10 = (undefined4 *)((int)puVar10 + -1);
                      goto LAB_08179b70;
                    }
                    puVar11 = (undefined4 *)((int)puVar10 + 1);
                    *(char *)puVar10 = '\0';
                    if (num <= local_30) break;
                    data[local_30] = puVar11;
                    puVar10 = puVar11;
                    local_30 = local_30 + 1;
                  }
                  else {
LAB_08179b70:
                    bVar12 = cVar1 == '\\';
                    *(char *)puVar10 = cVar1;
                    puVar10 = (undefined4 *)((int)puVar10 + 1);
                  }
                }
                *(char *)puVar11 = '\0';
                if ((local_30 == num) && (*pcVar7 == '\0')) {
                  data[local_30] = (char *)((int)puVar11 + 1);
                  iVar2 = sk_push((_STACK *)ptr->data,data);
                  if (iVar2 != 0) {
                    iVar2 = 0;
                    goto LAB_08179ae2;
                  }
                  fwrite("failure in sk_push\n",1,0x13,stderr);
                }
                else {
                  __fprintf_chk(stderr,1,
                                "wrong number of fields on line %ld (looking for field %d, got %d, \'%s\' left)\n"
                                ,local_34,num,local_30,pcVar7);
                }
                BUF_MEM_free(str);
                goto LAB_08179941;
              }
            }
LAB_08179ae2:
            local_34 = local_34 + 1;
          } while( true );
        }
      }
    }
  }
  BUF_MEM_free(str);
  fwrite("OPENSSL_malloc failure\n",1,0x17,stderr);
  if (ptr != (TXT_DB *)0x0) {
LAB_08179941:
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
  }
  return (TXT_DB *)0x0;
}

