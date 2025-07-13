class Solution {

     public static void findPerm(int n, int k,List<Integer>list ,    boolean[] used , int []count, StringBuilder sb, List<String>answer){

        if(list.size()==n){
            count[0]++;
            if(count[0]==k){
                for(int i=0; i<list.size(); i++){
                   sb.append(list.get(i));
                }
                answer.add(sb.toString());                
            }
            return;
        }

        for(int i=1; i<=n; i++){

                if(!used[i]){
                    list.add(i);
                    used[i]=true;
                    findPerm(n,k,list,used,count, sb, answer);
                    list.remove(list.size()-1);
                    used[i]=false;
                }
        }
    }
    public String getPermutation(int n, int k) {
        
        StringBuilder sb= new StringBuilder();

        List<String> answer =new ArrayList<>();

        List<Integer>list= new ArrayList<>();

        boolean []used= new boolean[n+1];

        used[0]= true;

        int []count= new int[1];

        findPerm(n,k,list, used, count,sb, answer);
        
        return answer.get(0);
    }
}