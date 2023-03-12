
void OPENSSL_wipe_cpu(void)

{
  uint in_lr;
  
  if ((in_lr & 1) == 0) {
    return;
  }
  return;
}

