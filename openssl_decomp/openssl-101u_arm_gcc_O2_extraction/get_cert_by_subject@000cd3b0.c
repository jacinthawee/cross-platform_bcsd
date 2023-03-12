
void get_cert_by_subject(X509_LOOKUP *param_1,int param_2,X509_NAME *param_3,undefined4 *param_4)

{
  BUF_MEM *str;
  ulong uVar1;
  int iVar2;
  char **ppcVar3;
  size_t sVar4;
  ulong *data;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  int iVar8;
  undefined4 *local_140;
  char *local_13c;
  int local_130;
  undefined **local_12c;
  ulong local_128 [2];
  stat sStack_120;
  undefined *local_c8 [19];
  undefined auStack_7c [8];
  X509_NAME *local_74;
  undefined auStack_60 [20];
  X509_NAME *local_4c;
  int local_2c;
  
  local_2c = __stack_chk_guard;
  if (param_3 == (X509_NAME *)0x0) goto LAB_000cd3fa;
  local_130 = param_2;
  if (param_2 == 1) {
    local_12c = local_c8;
    local_c8[0] = auStack_60;
    pcVar7 = "";
    local_4c = param_3;
    str = BUF_MEM_new();
    if (str != (BUF_MEM *)0x0) goto LAB_000cd42a;
LAB_000cd6ac:
    ERR_put_error(0xb,0x67,7,"by_dir.c",0x127);
  }
  else {
    if (param_2 == 2) {
      local_12c = local_c8;
      local_c8[0] = auStack_7c;
      pcVar7 = "r";
      local_74 = param_3;
      str = BUF_MEM_new();
      if (str == (BUF_MEM *)0x0) goto LAB_000cd6ac;
LAB_000cd42a:
      pcVar5 = param_1->method_data;
      iVar8 = 0;
      uVar1 = X509_NAME_hash(param_3);
      iVar2 = sk_num(*(_STACK **)(pcVar5 + 4));
      if (0 < iVar2) {
        do {
          ppcVar3 = (char **)sk_value(*(_STACK **)(pcVar5 + 4),iVar8);
          sVar4 = strlen(*ppcVar3);
          param_3 = (X509_NAME *)BUF_MEM_grow(str,sVar4 + 0x11);
          if (param_3 == (X509_NAME *)0x0) {
            ERR_put_error(0xb,0x67,0x41,"by_dir.c",0x135);
            goto LAB_000cd528;
          }
          if (param_2 == 2) {
            pcVar6 = ppcVar3[2];
            local_13c = pcVar6;
            if (pcVar6 != (char *)0x0) {
              local_128[0] = uVar1;
              CRYPTO_lock(5,0xb,"by_dir.c",0x13a);
              iVar2 = sk_find((_STACK *)ppcVar3[2],local_128);
              if (iVar2 < 0) {
                pcVar6 = (char *)0x0;
                local_13c = (char *)0x0;
              }
              else {
                local_13c = (char *)sk_value((_STACK *)ppcVar3[2],iVar2);
                pcVar6 = *(char **)(local_13c + 4);
              }
              CRYPTO_lock(6,0xb,"by_dir.c",0x143);
            }
            while( true ) {
              BIO_snprintf(str->data,str->max,"%s%c%08lx.%s%d",*ppcVar3,0x2f,uVar1,pcVar7,pcVar6);
              iVar2 = __xstat(3,str->data,&sStack_120);
              if ((iVar2 < 0) ||
                 (iVar2 = X509_load_crl_file(param_1,str->data,(int)ppcVar3[1]), iVar2 == 0)) break;
              pcVar6 = pcVar6 + 1;
            }
          }
          else if (param_2 == 1) {
            pcVar6 = (char *)0x0;
            while( true ) {
              BIO_snprintf(str->data,str->max,"%s%c%08lx.%s%d",*ppcVar3,0x2f,uVar1,pcVar7,pcVar6);
              iVar2 = __xstat(3,str->data,&sStack_120);
              if (iVar2 < 0) break;
              local_13c = (char *)X509_load_cert_file(param_1,str->data,(int)ppcVar3[1]);
              if (local_13c == (char *)0x0) goto LAB_000cd4be;
              pcVar6 = pcVar6 + 1;
            }
            local_13c = (char *)0x0;
          }
          else {
            pcVar6 = (char *)0x0;
            while( true ) {
              BIO_snprintf(str->data,str->max,"%s%c%08lx.%s%d",*ppcVar3,0x2f,uVar1,pcVar7,pcVar6);
              iVar2 = __xstat(3,str->data,&sStack_120);
              if (iVar2 < 0) break;
              pcVar6 = pcVar6 + 1;
            }
            local_13c = (char *)0x0;
          }
LAB_000cd4be:
          CRYPTO_lock(9,0xb,"by_dir.c",0x17c);
          iVar2 = sk_find((_STACK *)param_1->store_ctx->objs,&local_130);
          if (iVar2 == -1) {
            local_140 = (undefined4 *)0x0;
          }
          else {
            local_140 = (undefined4 *)sk_value((_STACK *)param_1->store_ctx->objs,iVar2);
          }
          CRYPTO_lock(10,0xb,"by_dir.c",0x182);
          if (param_2 == 2) {
            CRYPTO_lock(9,0xb,"by_dir.c",0x187);
            if ((local_13c == (char *)0x0) &&
               ((local_128[0] = uVar1, iVar2 = sk_find((_STACK *)ppcVar3[2],local_128), iVar2 < 0 ||
                (local_13c = (char *)sk_value((_STACK *)ppcVar3[2],iVar2), local_13c == (char *)0x0)
                ))) {
              data = (ulong *)CRYPTO_malloc(8,"by_dir.c",0x193);
              *data = uVar1;
              data[1] = (ulong)pcVar6;
              param_3 = (X509_NAME *)sk_push((_STACK *)ppcVar3[2],data);
              if (param_3 == (X509_NAME *)0x0) {
                CRYPTO_lock(10,0xb,"by_dir.c",0x197);
                CRYPTO_free(data);
                goto LAB_000cd528;
              }
            }
            else if (*(int *)(local_13c + 4) < (int)pcVar6) {
              *(char **)(local_13c + 4) = pcVar6;
            }
            CRYPTO_lock(10,0xb,"by_dir.c",0x19f);
          }
          if (local_140 != (undefined4 *)0x0) {
            param_3 = (X509_NAME *)0x1;
            *param_4 = *local_140;
            param_4[1] = local_140[1];
            goto LAB_000cd528;
          }
          iVar8 = iVar8 + 1;
          iVar2 = sk_num(*(_STACK **)(pcVar5 + 4));
        } while (iVar8 < iVar2);
      }
      param_3 = (X509_NAME *)0x0;
LAB_000cd528:
      BUF_MEM_free(str);
      goto LAB_000cd3fa;
    }
    ERR_put_error(0xb,0x67,0x70,"by_dir.c",0x122);
  }
  param_3 = (X509_NAME *)0x0;
LAB_000cd3fa:
  if (local_2c != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(param_3);
  }
  return;
}

