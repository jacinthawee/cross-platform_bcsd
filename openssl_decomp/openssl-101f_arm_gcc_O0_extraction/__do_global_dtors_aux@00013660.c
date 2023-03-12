
void __do_global_dtors_aux(void)

{
  if (completed_9551 == '\0') {
    deregister_tm_clones();
    completed_9551 = '\x01';
  }
  return;
}

