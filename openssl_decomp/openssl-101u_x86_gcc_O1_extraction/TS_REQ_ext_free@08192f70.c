
void TS_REQ_ext_free(int param_1)

{
  if (param_1 != 0) {
    sk_pop_free(*(_STACK **)(param_1 + 0x14),X509_EXTENSION_free);
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  return;
}

