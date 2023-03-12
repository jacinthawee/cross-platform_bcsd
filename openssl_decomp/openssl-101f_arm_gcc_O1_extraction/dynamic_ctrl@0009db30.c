
DSO * dynamic_ctrl(ENGINE *param_1,undefined4 param_2,DSO *param_3,DSO *param_4)

{
  DSO **__s;
  int iVar1;
  DSO *pDVar2;
  DSO **ppDVar3;
  char *pcVar4;
  uint uVar5;
  DSO *filename;
  int type;
  int mount;
  int line;
  CRYPTO_dynlock_value *l;
  char *file;
  f *f;
  DSO *file_00;
  int iVar6;
  int in_stack_ffffff30;
  void *local_c4;
  ERR_FNS *local_c0;
  CRYPTO_EX_DATA_IMPL *local_bc;
  int iStack_b8;
  undefined auStack_b4 [4];
  undefined auStack_b0 [4];
  int *local_ac;
  char *local_a8;
  CRYPTO_dynlock_value *local_a4;
  CRYPTO_dynlock_value *local_a0;
  CRYPTO_dynlock_value *local_9c;
  undefined auStack_98 [116];
  
  if (dynamic_ex_data_idx < 0) {
    in_stack_ffffff30 = 0x9daf5;
    iVar1 = ENGINE_get_ex_new_index
                      (0,(void *)0x0,(undefined1 *)0x0,(undefined1 *)0x0,
                       dynamic_data_ctx_free_func + 1);
    if (iVar1 == -1) {
      ERR_put_error(0x26,0xb5,0x90,"eng_dyn.c",0xf4);
      goto LAB_0009df1c;
    }
    CRYPTO_lock(9,0x1e,"eng_dyn.c",0xf7);
    if (dynamic_ex_data_idx < 0) {
      dynamic_ex_data_idx = iVar1;
    }
    CRYPTO_lock(10,0x1e,"eng_dyn.c",0xff);
  }
  __s = (DSO **)ENGINE_get_ex_data(param_1,dynamic_ex_data_idx);
  if (__s == (DSO **)0x0) {
    __s = (DSO **)CRYPTO_malloc(0x2c,"eng_dyn.c",0xbd);
    if (__s == (DSO **)0x0) {
      ERR_put_error(0x26,0xb7,0x41,"eng_dyn.c",0xc0);
LAB_0009df1c:
      ERR_put_error(0x26,0xb4,0x70,"eng_dyn.c",0x142);
      return (DSO *)0x0;
    }
    memset(__s,0,0x2c);
    *__s = (DSO *)0x0;
    __s[1] = (DSO *)0x0;
    __s[2] = (DSO *)0x0;
    __s[3] = (DSO *)0x0;
    __s[4] = (DSO *)0x0;
    __s[5] = (DSO *)0x0;
    __s[6] = (DSO *)0x0;
    __s[7] = (DSO *)"v_check";
    __s[8] = (DSO *)"bind_engine";
    __s[9] = (DSO *)0x1;
    pDVar2 = (DSO *)sk_new_null();
    __s[10] = pDVar2;
    if (pDVar2 == (DSO *)0x0) {
      ERR_put_error(0x26,0xb7,0x41,"eng_dyn.c",0xd1);
      CRYPTO_free(__s);
      goto LAB_0009df1c;
    }
    CRYPTO_lock(9,0x1e,"eng_dyn.c",0xd5);
    ppDVar3 = (DSO **)ENGINE_get_ex_data(param_1,dynamic_ex_data_idx);
    if (ppDVar3 == (DSO **)0x0) {
      ENGINE_set_ex_data(param_1,dynamic_ex_data_idx,__s);
      CRYPTO_lock(10,0x1e,"eng_dyn.c",0xde);
    }
    else {
      CRYPTO_lock(10,0x1e,"eng_dyn.c",0xde);
      CRYPTO_free(__s);
      __s = ppDVar3;
    }
  }
  if (*__s != (DSO *)0x0) {
    ERR_put_error(0x26,0xb4,100,"eng_dyn.c",0x14a);
    return (DSO *)0x0;
  }
  switch(param_2) {
  case 200:
    if ((param_4 != (DSO *)0x0) && (*(char *)&param_4->meth == '\0')) {
      param_4 = (DSO *)0x0;
    }
    if (__s[3] != (DSO *)0x0) {
      CRYPTO_free(__s[3]);
    }
    if (param_4 == (DSO *)0x0) {
      __s[3] = (DSO *)0x0;
    }
    else {
      param_4 = (DSO *)BUF_strdup((char *)param_4);
      __s[3] = param_4;
      if (param_4 != (DSO *)0x0) {
        param_4 = (DSO *)0x1;
      }
    }
    break;
  case 0xc9:
    param_4 = (DSO *)0x1;
    if (param_3 != (DSO *)0x0) {
      param_3 = (DSO *)0x1;
    }
    __s[4] = param_3;
    break;
  case 0xca:
    if ((param_4 != (DSO *)0x0) && (*(char *)&param_4->meth == '\0')) {
      param_4 = (DSO *)0x0;
    }
    if (__s[5] != (DSO *)0x0) {
      CRYPTO_free(__s[5]);
    }
    if (param_4 == (DSO *)0x0) {
      __s[5] = (DSO *)0x0;
    }
    else {
      param_4 = (DSO *)BUF_strdup((char *)param_4);
      __s[5] = param_4;
      if (param_4 != (DSO *)0x0) {
        param_4 = (DSO *)0x1;
      }
    }
    break;
  case 0xcb:
    if (param_3 < (DSO *)0x3) {
      __s[6] = param_3;
      return (DSO *)0x1;
    }
    iVar1 = 0x16c;
    goto LAB_0009dcb0;
  case 0xcc:
    if (param_3 < (DSO *)0x3) {
      __s[9] = param_3;
      return (DSO *)0x1;
    }
    iVar1 = 0x177;
    goto LAB_0009dcb0;
  case 0xcd:
    if ((param_4 != (DSO *)0x0) && (*(char *)&param_4->meth != '\0')) {
      pcVar4 = BUF_strdup((char *)param_4);
      if (pcVar4 != (char *)0x0) {
        sk_insert((_STACK *)__s[10],pcVar4,-1);
        return (DSO *)0x1;
      }
      ERR_put_error(0x26,0xb4,0x41,"eng_dyn.c",0x189);
      return (DSO *)0x0;
    }
    iVar1 = 0x181;
LAB_0009dcb0:
    param_4 = (DSO *)0x0;
    ERR_put_error(0x26,0xb4,0x8f,"eng_dyn.c",iVar1);
    break;
  case 0xce:
    pDVar2 = DSO_new();
    filename = __s[3];
    *__s = pDVar2;
    if (filename == (DSO *)0x0) {
      if (__s[5] == (DSO *)0x0) {
        return (DSO *)0x0;
      }
      filename = (DSO *)DSO_convert_filename(pDVar2,(char *)__s[5]);
      __s[3] = filename;
    }
    if (__s[9] == (DSO *)0x2) {
LAB_0009dd6a:
      iVar1 = sk_num((_STACK *)__s[10]);
      if (0 < iVar1) {
        iVar6 = 0;
        do {
          pcVar4 = (char *)sk_value((_STACK *)__s[10],iVar6);
          iVar6 = iVar6 + 1;
          pcVar4 = DSO_merge(*__s,(char *)__s[3],pcVar4);
          file_00 = (DSO *)0x0;
          if (pcVar4 == (char *)0x0) break;
          pDVar2 = DSO_load(*__s,pcVar4,(DSO_METHOD *)0x0,0);
          if (pDVar2 != (DSO *)0x0) {
            CRYPTO_free(pcVar4);
            goto LAB_0009de00;
          }
          CRYPTO_free(pcVar4);
        } while (iVar6 != iVar1);
      }
    }
    else {
      file_00 = (DSO *)0x0;
      pDVar2 = DSO_load(*__s,(char *)filename,(DSO_METHOD *)0x0,0);
      if (pDVar2 != (DSO *)0x0) {
LAB_0009de00:
        pDVar2 = (DSO *)DSO_bind_func(*__s,(char *)__s[8]);
        __s[2] = pDVar2;
        if (pDVar2 == (DSO *)0x0) {
          DSO_free(*__s);
          *__s = (DSO *)0x0;
          ERR_put_error(0x26,0xb6,0x68,"eng_dyn.c",0x1cf);
          return (DSO *)0x0;
        }
        if (__s[4] == (DSO *)0x0) {
          file_00 = (DSO *)DSO_bind_func(*__s,(char *)__s[7]);
          __s[1] = file_00;
          if ((file_00 == (DSO *)0x0) || (uVar5 = (*(code *)file_00)(0x20000), uVar5 < 0x20000)) {
            __s[2] = (DSO *)0x0;
            __s[1] = (DSO *)0x0;
            DSO_free(*__s);
            *__s = (DSO *)0x0;
            ERR_put_error(0x26,0xb6,0x91,"eng_dyn.c",0x1e7);
            return (DSO *)0x0;
          }
        }
        memcpy(auStack_98,param_1,0x70);
        local_c4 = ENGINE_get_static_state();
        local_c0 = ERR_get_implementation();
        local_bc = CRYPTO_get_ex_data_implementation();
        f = (f *)auStack_b0;
        local_ac = &iStack_b8;
        CRYPTO_get_mem_functions((m *)local_ac,(r *)auStack_b4,f);
        CRYPTO_get_locking_callback((int)local_ac,type,(char *)f,(int)file_00);
        local_a8 = (char *)CRYPTO_get_add_lock_callback
                                     (local_ac,mount,(int)f,(char *)file_00,in_stack_ffffff30);
        local_9c = CRYPTO_get_dynlock_create_callback(local_a8,line);
        local_a4 = local_9c;
        CRYPTO_get_dynlock_lock_callback((int)local_9c,l,(char *)f,(int)file_00);
        local_a0 = local_9c;
        CRYPTO_get_dynlock_destroy_callback(local_9c,file,(int)f);
        engine_set_all_null(param_1);
        iVar1 = (*(code *)__s[2])(param_1,__s[5],&local_c4);
        if (iVar1 == 0) {
          __s[2] = (DSO *)0x0;
          __s[1] = (DSO *)0x0;
          DSO_free(*__s);
          *__s = (DSO *)0x0;
          ERR_put_error(0x26,0xb6,0x6d,"eng_dyn.c",0x209);
          memcpy(param_1,auStack_98,0x70);
          return (DSO *)0x0;
        }
        if ((0 < (int)__s[6]) && (iVar1 = ENGINE_add(param_1), iVar1 == 0)) {
          if (1 < (int)__s[6]) {
            ERR_put_error(0x26,0xb6,0x67,"eng_dyn.c",0x21c);
            return (DSO *)0x0;
          }
          ERR_clear_error();
        }
        return (DSO *)0x1;
      }
      if (__s[9] != (DSO *)0x0) goto LAB_0009dd6a;
    }
    ERR_put_error(0x26,0xb6,0x84,"eng_dyn.c",0x1c2);
    DSO_free(*__s);
    param_4 = (DSO *)0x0;
    *__s = (DSO *)0x0;
    break;
  default:
    param_4 = (DSO *)0x0;
    ERR_put_error(0x26,0xb4,0x77,"eng_dyn.c",0x192);
  }
  return param_4;
}

