
undefined4
get_cert_by_subject(X509_LOOKUP *param_1,int param_2,X509_NAME *param_3,undefined4 *param_4)

{
  char *pcVar1;
  undefined4 uVar2;
  BUF_MEM *str;
  ulong uVar3;
  int iVar4;
  char **ppcVar5;
  size_t sVar6;
  int mode;
  void *mode_00;
  undefined4 *mode_01;
  ulong *data;
  ulong uVar7;
  int in_GS_OFFSET;
  undefined1 *local_148;
  int local_140;
  undefined4 *local_138;
  void *local_134;
  int local_124;
  undefined **local_120;
  ulong local_11c [2];
  stat local_114;
  undefined *local_bc [19];
  undefined local_70 [8];
  X509_NAME *local_68;
  undefined local_54 [20];
  X509_NAME *local_40;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (param_3 != (X509_NAME *)0x0) {
    local_124 = param_2;
    if (param_2 == 1) {
      local_120 = local_bc;
      local_bc[0] = local_54;
      local_40 = param_3;
      local_148 = &DAT_081eca46;
      str = BUF_MEM_new();
      if (str != (BUF_MEM *)0x0) goto LAB_0816638b;
LAB_08166765:
      ERR_put_error(0xb,0x67,7,"by_dir.c",0x127);
    }
    else {
      if (param_2 == 2) {
        local_120 = local_bc;
        local_bc[0] = local_70;
        local_68 = param_3;
        local_148 = &DAT_082006ac;
        str = BUF_MEM_new();
        if (str == (BUF_MEM *)0x0) goto LAB_08166765;
LAB_0816638b:
        pcVar1 = param_1->method_data;
        uVar3 = X509_NAME_hash(param_3);
        for (local_140 = 0; iVar4 = sk_num(*(_STACK **)(pcVar1 + 4)), local_140 < iVar4;
            local_140 = local_140 + 1) {
          ppcVar5 = (char **)sk_value(*(_STACK **)(pcVar1 + 4),local_140);
          sVar6 = strlen(*ppcVar5);
          iVar4 = BUF_MEM_grow(str,sVar6 + 0x11);
          if (iVar4 == 0) {
            uVar2 = 0;
            ERR_put_error(0xb,0x67,0x41,"by_dir.c",0x135);
            goto LAB_08166787;
          }
          if (param_2 == 2) {
            if (ppcVar5[2] == (char *)0x0) {
              local_134 = (void *)0x0;
              uVar7 = 0;
            }
            else {
              local_11c[0] = uVar3;
              CRYPTO_lock(iVar4,5,(char *)0xb,(int)"by_dir.c");
              mode_00 = (void *)sk_find((_STACK *)ppcVar5[2],local_11c);
              if ((int)mode_00 < 0) {
                local_134 = (void *)0x0;
                uVar7 = 0;
              }
              else {
                mode_00 = sk_value((_STACK *)ppcVar5[2],(int)mode_00);
                uVar7 = *(ulong *)((int)mode_00 + 4);
                local_134 = mode_00;
              }
              CRYPTO_lock((int)mode_00,6,(char *)0xb,(int)"by_dir.c");
            }
            while( true ) {
              BIO_snprintf(str->data,str->max,"%s%c%08lx.%s%d",*ppcVar5,0x2f,uVar3,local_148,uVar7);
              iVar4 = __xstat(3,str->data,&local_114);
              if ((iVar4 < 0) ||
                 (iVar4 = X509_load_crl_file(param_1,str->data,(int)ppcVar5[1]), iVar4 == 0)) break;
              uVar7 = uVar7 + 1;
            }
            CRYPTO_lock(iVar4,9,(char *)0xb,(int)"by_dir.c");
            mode_01 = (undefined4 *)sk_find((_STACK *)param_1->store_ctx->objs,&local_124);
            if (mode_01 == (undefined4 *)0xffffffff) {
              CRYPTO_lock(-1,10,(char *)0xb,(int)"by_dir.c");
              local_138 = (undefined4 *)0x0;
            }
            else {
              local_138 = (undefined4 *)sk_value((_STACK *)param_1->store_ctx->objs,(int)mode_01);
              mode_01 = local_138;
              CRYPTO_lock((int)local_138,10,(char *)0xb,(int)"by_dir.c");
            }
            CRYPTO_lock((int)mode_01,9,(char *)0xb,(int)"by_dir.c");
            if ((local_134 == (void *)0x0) &&
               ((local_11c[0] = uVar3, iVar4 = sk_find((_STACK *)ppcVar5[2],local_11c), iVar4 < 0 ||
                (local_134 = sk_value((_STACK *)ppcVar5[2],iVar4), local_134 == (void *)0x0)))) {
              data = (ulong *)CRYPTO_malloc(8,"by_dir.c",0x193);
              *data = uVar3;
              data[1] = uVar7;
              local_134 = (void *)sk_push((_STACK *)ppcVar5[2],data);
              if (local_134 == (void *)0x0) {
                uVar2 = 0;
                CRYPTO_lock(0,10,(char *)0xb,(int)"by_dir.c");
                CRYPTO_free(data);
                goto LAB_08166787;
              }
            }
            else if (*(int *)((int)local_134 + 4) < (int)uVar7) {
              *(ulong *)((int)local_134 + 4) = uVar7;
            }
            CRYPTO_lock((int)local_134,10,(char *)0xb,(int)"by_dir.c");
joined_r0x081666bc:
            if (local_138 != (undefined4 *)0x0) {
              uVar2 = 1;
              *param_4 = *local_138;
              param_4[1] = local_138[1];
              goto LAB_08166787;
            }
          }
          else {
            iVar4 = 0;
            if (param_2 == 1) {
              while( true ) {
                BIO_snprintf(str->data,str->max,"%s%c%08lx.%s%d",*ppcVar5,0x2f,uVar3,local_148,iVar4
                            );
                mode = __xstat(3,str->data,&local_114);
                if ((mode < 0) ||
                   (mode = X509_load_cert_file(param_1,str->data,(int)ppcVar5[1]), mode == 0))
                break;
                iVar4 = iVar4 + 1;
              }
            }
            else {
              iVar4 = 0;
              while( true ) {
                BIO_snprintf(str->data,str->max,"%s%c%08lx.%s%d",*ppcVar5,0x2f,uVar3,local_148,iVar4
                            );
                mode = __xstat(3,str->data,&local_114);
                if (mode < 0) break;
                iVar4 = iVar4 + 1;
              }
            }
            CRYPTO_lock(mode,9,(char *)0xb,(int)"by_dir.c");
            iVar4 = sk_find((_STACK *)param_1->store_ctx->objs,&local_124);
            if (iVar4 != -1) {
              local_138 = (undefined4 *)sk_value((_STACK *)param_1->store_ctx->objs,iVar4);
              CRYPTO_lock((int)local_138,10,(char *)0xb,(int)"by_dir.c");
              goto joined_r0x081666bc;
            }
            CRYPTO_lock(-1,10,(char *)0xb,(int)"by_dir.c");
          }
        }
        uVar2 = 0;
LAB_08166787:
        BUF_MEM_free(str);
        goto LAB_08166335;
      }
      ERR_put_error(0xb,0x67,0x70,"by_dir.c",0x122);
    }
  }
  uVar2 = 0;
LAB_08166335:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

