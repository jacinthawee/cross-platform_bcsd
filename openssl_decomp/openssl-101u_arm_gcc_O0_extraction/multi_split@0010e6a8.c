
void multi_split(BIO *param_1,char *param_2,_STACK **param_3)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  size_t sVar4;
  _STACK *st;
  int len;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  BIO_METHOD *type;
  size_t __n;
  char cVar8;
  BIO *b;
  char acStack_42d [1025];
  int local_2c;
  
  cVar8 = '\0';
  b = (BIO *)0x0;
  local_2c = __stack_chk_guard;
  sVar4 = strlen(param_2);
  st = sk_new_null();
  *param_3 = st;
  iVar6 = 1;
  bVar1 = false;
LAB_0010e6e0:
  do {
    len = BIO_gets(param_1,acStack_42d + 1,0x400);
    if (len < 1) {
      uVar7 = 0;
LAB_0010e746:
      if (local_2c != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail(uVar7);
      }
      return;
    }
    __n = sVar4;
    if (sVar4 == 0xffffffff) {
      __n = strlen(param_2);
    }
    if (((len <= (int)(__n + 1)) || (iVar5 = strncmp(acStack_42d + 1,"--",2), iVar5 != 0)) ||
       (iVar5 = strncmp(acStack_42d + 3,param_2,__n), iVar5 != 0)) {
      if (cVar8 != '\0') {
        bVar3 = false;
        do {
          while (bVar2 = bVar3, acStack_42d[len] != '\n') {
            if ((acStack_42d[len] != '\r') || (len = len + -1, bVar3 = bVar2, len == 0))
            goto LAB_0010e782;
          }
          len = len + -1;
          bVar2 = true;
          bVar3 = true;
        } while (len != 0);
LAB_0010e782:
        if (iVar6 == 0) {
          if (bVar1) {
            BIO_write(b,"\r\n",2);
          }
        }
        else {
          if (b != (BIO *)0x0) {
            sk_push(st,b);
          }
          type = BIO_s_mem();
          b = BIO_new(type);
          BIO_ctrl(b,0x82,0,(void *)0x0);
        }
        iVar6 = len;
        bVar1 = bVar2;
        if (len != 0) {
          BIO_write(b,acStack_42d + 1,len);
          iVar6 = 0;
        }
      }
      goto LAB_0010e6e0;
    }
    iVar6 = strncmp(acStack_42d + __n + 3,"--",2);
    if (iVar6 == 0) {
      sk_push(st,b);
      uVar7 = 1;
      goto LAB_0010e746;
    }
    cVar8 = cVar8 + '\x01';
    iVar6 = 1;
  } while( true );
}

