import javax.swing.*;
import javax.swing.JSlider;
import javax.swing.JFrame;
import  javax.swing.JButton;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

public class Window {
 private JSlider slider;
 private  JButton btnGo;
 private JButton btnStart1, btnStart2, btnStop1, btnStop2;
 private JFrame win;
 private  JSpinner spinner1,spinner2;
 private Thread Thread1, Thread2;
 private int semaphore;
 
 Window(int w, int h){
     //Window
     win = new JFrame("Lab1");
     win.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
     win.setSize(w,h);
     win.setLayout(null);
     //slider
     slider = new JSlider(0,100,50);
     slider.setPaintTicks(true);
     slider.setMajorTickSpacing(10);
     slider.setPaintLabels(true);
     slider.setBounds(10, 10, 200, 50);
     //Button "Go:
     btnGo = new JButton("Go");
     btnGo.setBounds(55, 70, 100,40);
     btnGo.addMouseListener(new MouseListener() {
         @Override
         public void mouseClicked(MouseEvent e) {
             int p1 = (int) spinner1.getValue();
             int p2 = (int) spinner2.getValue();
            ThreadsGo(p1,p2);
         }

         @Override
         public void mousePressed(MouseEvent e) {

         }

         @Override
         public void mouseReleased(MouseEvent e) {

         }

         @Override
         public void mouseEntered(MouseEvent e) {

         }

         @Override
         public void mouseExited(MouseEvent e) {

         }
     });
     //Spiners
     spinner1 = new JSpinner();
     spinner1.setBounds(30,150,30,30);
     spinner2 = new JSpinner();
     spinner2.setBounds(130,150,30,30);
     //Buttons "Start 1/2" and "Stop 1/2"
     btnStart1 = new JButton("Start1");
     btnStart1.setBounds(10, 200,100,40);
     btnStart2 = new JButton("Start2");
     btnStart2.setBounds(110, 200,100,40);
     btnStop1 = new JButton("Stop1");
     btnStop1.setBounds(10, 250,100,40);
     btnStop2 = new JButton("Stop2");
     btnStop2.setBounds(110, 250,100,40);
     btnStart1.addMouseListener(new MouseListener() {
         @Override
         public void mouseClicked(MouseEvent e) {
            if(semaphore==0 || semaphore==-1){
                Thread1 = new ThreadGo(slider, 10,true);
                Thread1.setPriority(1);
                Thread1.start();
                semaphore=1;
                System.out.println(semaphore);
            }

         }

         @Override
         public void mousePressed(MouseEvent e) {

         }

         @Override
         public void mouseReleased(MouseEvent e) {

         }

         @Override
         public void mouseEntered(MouseEvent e) {

         }

         @Override
         public void mouseExited(MouseEvent e) {

         }
     });
     btnStart2.addMouseListener(new MouseListener() {
         @Override
         public void mouseClicked(MouseEvent e) {
             if(semaphore==0 || semaphore==-2){
                 Thread2 = new ThreadGo(slider, 90,true);
                 Thread2.setPriority(10);
                 Thread2.start();
                 semaphore=2;
                 System.out.println(semaphore);
             }
         }

         @Override
         public void mousePressed(MouseEvent e) {

         }

         @Override
         public void mouseReleased(MouseEvent e) {

         }

         @Override
         public void mouseEntered(MouseEvent e) {

         }

         @Override
         public void mouseExited(MouseEvent e) {

         }
     });
     btnStop1.addMouseListener(new MouseListener() {
         @Override
         public void mouseClicked(MouseEvent e) {
            if(semaphore==1){
                Thread1.destroy();
                semaphore=-2;
                System.out.println(semaphore);
            }
         }

         @Override
         public void mousePressed(MouseEvent e) {

         }

         @Override
         public void mouseReleased(MouseEvent e) {

         }

         @Override
         public void mouseEntered(MouseEvent e) {

         }

         @Override
         public void mouseExited(MouseEvent e) {

         }
     });
     btnStop2.addMouseListener(new MouseListener() {
         @Override
         public void mouseClicked(MouseEvent e) {
             if(semaphore==2){
                 Thread1.interrupt();
                 semaphore=-1;
                 System.out.println(semaphore);
             }
         }

         @Override
         public void mousePressed(MouseEvent e) {

         }

         @Override
         public void mouseReleased(MouseEvent e) {

         }

         @Override
         public void mouseEntered(MouseEvent e) {

         }

         @Override
         public void mouseExited(MouseEvent e) {

         }
     });

     //Adding
     semaphore=0;
     win.add(btnGo);
     win.add(slider);
     win.add(spinner1);
     win.add(spinner2);
     win.add(btnStart1);
     win.add(btnStart2);
     win.add(btnStop1);
     win.add(btnStop2);
     win.setVisible(true);

 }
 
private void ThreadsGo(int p1, int p2){
     Thread1 = new ThreadGo(slider,10, true);
     Thread2 = new ThreadGo(slider,90,true);
     Thread1.setPriority(p1);
     Thread2.setPriority(p2);
     Thread1.start();
     Thread2.start();
}
  class ThreadGo extends Thread{
     private  JSlider slider;
     private int pos;
     private boolean life;

     ThreadGo(JSlider slider, int pos, boolean life){
         this.pos = pos;
         this.slider = slider;
         this.life = life;
     }
     
     void destroy(){
         life = false;
     }
     
     @Override
     public void run(){
         life=true;
         while (life) {
             synchronized (slider) {
                     slider.setValue(pos);
             }
             try {
                 ThreadGo.sleep(100);
             } catch (InterruptedException e) {
                 throw new RuntimeException(e);
             }
         }
     }

 }

}
