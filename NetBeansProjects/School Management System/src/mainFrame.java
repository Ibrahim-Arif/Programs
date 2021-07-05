import java.awt.Color;

public class mainFrame extends javax.swing.JFrame {

    public mainFrame() {
        initComponents();
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jPanel2 = new javax.swing.JPanel();
        taskbar = new javax.swing.JPanel();
        staff = new javax.swing.JPanel();
        jLabel1 = new javax.swing.JLabel();
        jLabel2 = new javax.swing.JLabel();
        student = new javax.swing.JPanel();
        jLabel3 = new javax.swing.JLabel();
        jLabel4 = new javax.swing.JLabel();
        timetable = new javax.swing.JPanel();
        jLabel5 = new javax.swing.JLabel();
        jLabel6 = new javax.swing.JLabel();
        classes = new javax.swing.JPanel();
        jLabel7 = new javax.swing.JLabel();
        jLabel8 = new javax.swing.JLabel();
        taskbar1 = new javax.swing.JPanel();
        jLabel13 = new javax.swing.JLabel();
        jLabel14 = new javax.swing.JLabel();
        jLabel15 = new javax.swing.JLabel();
        close = new javax.swing.JLabel();
        staff1 = new javax.swing.JPanel();
        jLabel9 = new javax.swing.JLabel();
        jLabel10 = new javax.swing.JLabel();
        staff2 = new javax.swing.JPanel();
        jLabel11 = new javax.swing.JLabel();
        jLabel12 = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setBounds(new java.awt.Rectangle(0, 0, 0, 0));
        setUndecorated(true);
        setResizable(false);

        jPanel2.setBackground(new java.awt.Color(255, 255, 255));
        jPanel2.setBorder(javax.swing.BorderFactory.createMatteBorder(3, 3, 3, 3, new java.awt.Color(45, 118, 232)));
        jPanel2.setForeground(new java.awt.Color(45, 118, 232));
        jPanel2.setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        taskbar.setBackground(new java.awt.Color(45, 118, 232));

        javax.swing.GroupLayout taskbarLayout = new javax.swing.GroupLayout(taskbar);
        taskbar.setLayout(taskbarLayout);
        taskbarLayout.setHorizontalGroup(
            taskbarLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 740, Short.MAX_VALUE)
        );
        taskbarLayout.setVerticalGroup(
            taskbarLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 20, Short.MAX_VALUE)
        );

        jPanel2.add(taskbar, new org.netbeans.lib.awtextra.AbsoluteConstraints(0, 540, 740, 20));

        staff.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                staffMouseClicked(evt);
            }
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                staffMouseEntered(evt);
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                staffMouseExited(evt);
            }
        });

        jLabel1.setIcon(new javax.swing.ImageIcon(getClass().getResource("/icons/icons8_staff_50px.png"))); // NOI18N

        jLabel2.setFont(new java.awt.Font("Tahoma", 1, 12)); // NOI18N
        jLabel2.setForeground(new java.awt.Color(45, 118, 232));
        jLabel2.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel2.setText("Staff");

        javax.swing.GroupLayout staffLayout = new javax.swing.GroupLayout(staff);
        staff.setLayout(staffLayout);
        staffLayout.setHorizontalGroup(
            staffLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(staffLayout.createSequentialGroup()
                .addGap(30, 30, 30)
                .addGroup(staffLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(jLabel2, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(jLabel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addContainerGap(30, Short.MAX_VALUE))
        );
        staffLayout.setVerticalGroup(
            staffLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, staffLayout.createSequentialGroup()
                .addGap(18, 18, 18)
                .addComponent(jLabel1, javax.swing.GroupLayout.PREFERRED_SIZE, 42, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jLabel2)
                .addContainerGap(19, Short.MAX_VALUE))
        );

        jPanel2.add(staff, new org.netbeans.lib.awtextra.AbsoluteConstraints(170, 350, 110, 100));

        student.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                studentMouseClicked(evt);
            }
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                studentMouseEntered(evt);
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                studentMouseExited(evt);
            }
        });

        jLabel3.setIcon(new javax.swing.ImageIcon(getClass().getResource("/icons/icons8_team_50px_1.png"))); // NOI18N

        jLabel4.setFont(new java.awt.Font("Tahoma", 1, 12)); // NOI18N
        jLabel4.setForeground(new java.awt.Color(45, 118, 232));
        jLabel4.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel4.setText("Student");

        javax.swing.GroupLayout studentLayout = new javax.swing.GroupLayout(student);
        student.setLayout(studentLayout);
        studentLayout.setHorizontalGroup(
            studentLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(studentLayout.createSequentialGroup()
                .addGap(30, 30, 30)
                .addGroup(studentLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(jLabel4, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(jLabel3, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addContainerGap(30, Short.MAX_VALUE))
        );
        studentLayout.setVerticalGroup(
            studentLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, studentLayout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jLabel3)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jLabel4)
                .addContainerGap(19, Short.MAX_VALUE))
        );

        jPanel2.add(student, new org.netbeans.lib.awtextra.AbsoluteConstraints(170, 220, 110, 100));

        timetable.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                timetableMouseClicked(evt);
            }
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                timetableMouseEntered(evt);
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                timetableMouseExited(evt);
            }
        });

        jLabel5.setIcon(new javax.swing.ImageIcon(getClass().getResource("/icons/icons8_timetable_50px_1.png"))); // NOI18N

        jLabel6.setFont(new java.awt.Font("Tahoma", 1, 12)); // NOI18N
        jLabel6.setForeground(new java.awt.Color(45, 118, 232));
        jLabel6.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel6.setText("Timetable");

        javax.swing.GroupLayout timetableLayout = new javax.swing.GroupLayout(timetable);
        timetable.setLayout(timetableLayout);
        timetableLayout.setHorizontalGroup(
            timetableLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(timetableLayout.createSequentialGroup()
                .addGap(30, 30, 30)
                .addGroup(timetableLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(jLabel6, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(jLabel5, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addContainerGap(21, Short.MAX_VALUE))
        );
        timetableLayout.setVerticalGroup(
            timetableLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, timetableLayout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jLabel5)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jLabel6)
                .addContainerGap(19, Short.MAX_VALUE))
        );

        jPanel2.add(timetable, new org.netbeans.lib.awtextra.AbsoluteConstraints(310, 220, 110, 100));

        classes.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                classesMouseClicked(evt);
            }
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                classesMouseEntered(evt);
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                classesMouseExited(evt);
            }
        });

        jLabel7.setIcon(new javax.swing.ImageIcon(getClass().getResource("/icons/icons8_list_50px.png"))); // NOI18N

        jLabel8.setFont(new java.awt.Font("Tahoma", 1, 12)); // NOI18N
        jLabel8.setForeground(new java.awt.Color(45, 118, 232));
        jLabel8.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel8.setText("Classes");

        javax.swing.GroupLayout classesLayout = new javax.swing.GroupLayout(classes);
        classes.setLayout(classesLayout);
        classesLayout.setHorizontalGroup(
            classesLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(classesLayout.createSequentialGroup()
                .addGap(30, 30, 30)
                .addGroup(classesLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(jLabel8, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(jLabel7, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addContainerGap(30, Short.MAX_VALUE))
        );
        classesLayout.setVerticalGroup(
            classesLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, classesLayout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jLabel7)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jLabel8)
                .addContainerGap(19, Short.MAX_VALUE))
        );

        jPanel2.add(classes, new org.netbeans.lib.awtextra.AbsoluteConstraints(450, 220, 110, 100));

        taskbar1.setBackground(new java.awt.Color(45, 118, 232));

        jLabel13.setFont(new java.awt.Font("Tahoma", 1, 24)); // NOI18N
        jLabel13.setForeground(new java.awt.Color(255, 255, 255));
        jLabel13.setText("SARGODHA");

        jLabel14.setIcon(new javax.swing.ImageIcon(getClass().getResource("/icons/logo school.jpg"))); // NOI18N

        jLabel15.setFont(new java.awt.Font("Tahoma", 1, 28)); // NOI18N
        jLabel15.setForeground(new java.awt.Color(255, 255, 255));
        jLabel15.setText("GREEN PUBLIC SCHOOL");

        close.setFont(new java.awt.Font("Tahoma", 1, 18)); // NOI18N
        close.setForeground(new java.awt.Color(255, 255, 255));
        close.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        close.setText("x");
        close.setVerticalAlignment(javax.swing.SwingConstants.TOP);
        close.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                closeMouseClicked(evt);
            }
        });

        javax.swing.GroupLayout taskbar1Layout = new javax.swing.GroupLayout(taskbar1);
        taskbar1.setLayout(taskbar1Layout);
        taskbar1Layout.setHorizontalGroup(
            taskbar1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, taskbar1Layout.createSequentialGroup()
                .addGap(34, 34, 34)
                .addComponent(jLabel14, javax.swing.GroupLayout.PREFERRED_SIZE, 202, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 52, Short.MAX_VALUE)
                .addGroup(taskbar1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, taskbar1Layout.createSequentialGroup()
                        .addComponent(close, javax.swing.GroupLayout.PREFERRED_SIZE, 23, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addContainerGap())
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, taskbar1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                        .addComponent(jLabel13, javax.swing.GroupLayout.PREFERRED_SIZE, 452, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addComponent(jLabel15, javax.swing.GroupLayout.PREFERRED_SIZE, 452, javax.swing.GroupLayout.PREFERRED_SIZE))))
        );
        taskbar1Layout.setVerticalGroup(
            taskbar1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(taskbar1Layout.createSequentialGroup()
                .addGap(20, 20, 20)
                .addComponent(jLabel14)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, taskbar1Layout.createSequentialGroup()
                .addComponent(close)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addComponent(jLabel15, javax.swing.GroupLayout.PREFERRED_SIZE, 45, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jLabel13, javax.swing.GroupLayout.PREFERRED_SIZE, 45, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(27, 27, 27))
        );

        jPanel2.add(taskbar1, new org.netbeans.lib.awtextra.AbsoluteConstraints(0, 0, 740, 150));

        jLabel9.setIcon(new javax.swing.ImageIcon(getClass().getResource("/icons/icons8_staff_50px.png"))); // NOI18N

        jLabel10.setFont(new java.awt.Font("Tahoma", 1, 12)); // NOI18N
        jLabel10.setForeground(new java.awt.Color(45, 118, 232));
        jLabel10.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel10.setText("Staff");

        javax.swing.GroupLayout staff1Layout = new javax.swing.GroupLayout(staff1);
        staff1.setLayout(staff1Layout);
        staff1Layout.setHorizontalGroup(
            staff1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(staff1Layout.createSequentialGroup()
                .addGap(30, 30, 30)
                .addGroup(staff1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(jLabel10, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(jLabel9, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addContainerGap(30, Short.MAX_VALUE))
        );
        staff1Layout.setVerticalGroup(
            staff1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, staff1Layout.createSequentialGroup()
                .addGap(18, 18, 18)
                .addComponent(jLabel9, javax.swing.GroupLayout.PREFERRED_SIZE, 42, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jLabel10)
                .addContainerGap(19, Short.MAX_VALUE))
        );

        jPanel2.add(staff1, new org.netbeans.lib.awtextra.AbsoluteConstraints(310, 350, 110, 100));

        jLabel11.setIcon(new javax.swing.ImageIcon(getClass().getResource("/icons/icons8_staff_50px.png"))); // NOI18N

        jLabel12.setFont(new java.awt.Font("Tahoma", 1, 12)); // NOI18N
        jLabel12.setForeground(new java.awt.Color(45, 118, 232));
        jLabel12.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel12.setText("Staff");

        javax.swing.GroupLayout staff2Layout = new javax.swing.GroupLayout(staff2);
        staff2.setLayout(staff2Layout);
        staff2Layout.setHorizontalGroup(
            staff2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(staff2Layout.createSequentialGroup()
                .addGap(30, 30, 30)
                .addGroup(staff2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(jLabel12, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(jLabel11, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addContainerGap(30, Short.MAX_VALUE))
        );
        staff2Layout.setVerticalGroup(
            staff2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, staff2Layout.createSequentialGroup()
                .addGap(18, 18, 18)
                .addComponent(jLabel11, javax.swing.GroupLayout.PREFERRED_SIZE, 42, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jLabel12)
                .addContainerGap(19, Short.MAX_VALUE))
        );

        jPanel2.add(staff2, new org.netbeans.lib.awtextra.AbsoluteConstraints(450, 350, 110, 100));

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel2, javax.swing.GroupLayout.PREFERRED_SIZE, 737, javax.swing.GroupLayout.PREFERRED_SIZE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                .addGap(0, 0, Short.MAX_VALUE)
                .addComponent(jPanel2, javax.swing.GroupLayout.PREFERRED_SIZE, 558, javax.swing.GroupLayout.PREFERRED_SIZE))
        );

        pack();
        setLocationRelativeTo(null);
    }// </editor-fold>//GEN-END:initComponents

    private void closeMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_closeMouseClicked
        System.exit(0);
    }//GEN-LAST:event_closeMouseClicked
/**/
    private void studentMouseEntered(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_studentMouseEntered
        // TODO add your handling code here:
        student.setBackground(Color.lightGray);
    }//GEN-LAST:event_studentMouseEntered

    private void studentMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_studentMouseExited
        // TODO add your handling code here:
        student.setBackground(new Color(240,240,240));
    }//GEN-LAST:event_studentMouseExited

    private void timetableMouseEntered(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_timetableMouseEntered
        // TODO add your handling code here:
        timetable.setBackground(Color.lightGray);
    }//GEN-LAST:event_timetableMouseEntered

    private void timetableMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_timetableMouseExited
        // TODO add your handling code here:
        timetable.setBackground(new Color(240,240,240));
    }//GEN-LAST:event_timetableMouseExited

    private void classesMouseEntered(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_classesMouseEntered
        // TODO add your handling code here:
        classes.setBackground(Color.lightGray);
    }//GEN-LAST:event_classesMouseEntered

    private void classesMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_classesMouseExited
        // TODO add your handling code here:
        classes.setBackground(new Color(240,240,240));
    }//GEN-LAST:event_classesMouseExited

    private void staffMouseEntered(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_staffMouseEntered
        // TODO add your handling code here:
        staff.setBackground(Color.lightGray);
    }//GEN-LAST:event_staffMouseEntered

    private void staffMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_staffMouseExited
        // TODO add your handling code here:
        staff.setBackground(new Color(240,240,240));
    }//GEN-LAST:event_staffMouseExited

    private void studentMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_studentMouseClicked
        // TODO add your handling code here:
        studentFrame SF = new studentFrame();
        SF.setVisible(true);
        this.hide();
    }//GEN-LAST:event_studentMouseClicked

    private void timetableMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_timetableMouseClicked
        // TODO add your handling code here:
        timetableFrame TTF = new timetableFrame();
        TTF.setVisible(true);
        this.hide();
    }//GEN-LAST:event_timetableMouseClicked

    private void classesMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_classesMouseClicked
        // TODO add your handling code here:
        classesFrame CF = new classesFrame();
        CF.setVisible(true);
        this.hide();
    }//GEN-LAST:event_classesMouseClicked

    private void staffMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_staffMouseClicked
        // TODO add your handling code here:
        staff SF = new staff();
        SF.setVisible(true);
        this.hide();
    }//GEN-LAST:event_staffMouseClicked

    public static void main(String args[]) {

        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new mainFrame().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JPanel classes;
    private javax.swing.JLabel close;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel10;
    private javax.swing.JLabel jLabel11;
    private javax.swing.JLabel jLabel12;
    private javax.swing.JLabel jLabel13;
    private javax.swing.JLabel jLabel14;
    private javax.swing.JLabel jLabel15;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JLabel jLabel7;
    private javax.swing.JLabel jLabel8;
    private javax.swing.JLabel jLabel9;
    private javax.swing.JPanel jPanel2;
    private javax.swing.JPanel staff;
    private javax.swing.JPanel staff1;
    private javax.swing.JPanel staff2;
    private javax.swing.JPanel student;
    private javax.swing.JPanel taskbar;
    private javax.swing.JPanel taskbar1;
    private javax.swing.JPanel timetable;
    // End of variables declaration//GEN-END:variables
}
